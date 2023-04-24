#include <SFML/Graphics.hpp>
#include <cmath>
#include<iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::Vertex line[100][2];
    
    
    sf::Vector2i mousePos;

    float posX;
    float posY;

    float endPoint=0;

    float points[100][2];
    

    for (int i = 0; i < 100; i++) {
        points[i][0] = sin(endPoint) * 500.0f;
        points[i][1] = cos(endPoint) * 500.0f;
        endPoint += 0.1f;
    }

  



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        mousePos = sf::Mouse::getPosition(window);

        posX = (float)mousePos.x;
        posY = (float)mousePos.y;

        

        
       
       

        for (int i = 0; i < 100;i++) {


            line[i][0].position = sf::Vector2f(posX, posY);
            line[i][1].position = sf::Vector2f(posX + points[i][0], posY + points[i][1]);
            

            
            window.clear();
            
            window.draw(line[i],100,sf::Lines);
            window.display();

        

        }

        

    }



    return 0;
}