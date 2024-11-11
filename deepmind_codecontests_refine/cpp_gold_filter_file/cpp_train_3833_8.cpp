#include <iostream>

int main()
{
  int A,B,C;
  std::cin>>A>>B>>C;
  std::cout<<B+(A+B+1<C?A+B+1:C)<<std::endl;
}