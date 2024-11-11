#include <iostream>

int main()
{
  int a, b;
  std::in >> a >> b;
  
  int r = a *b;
  
  std::cout << (r % 2 == 0 ? "Even" : "Odd");
}