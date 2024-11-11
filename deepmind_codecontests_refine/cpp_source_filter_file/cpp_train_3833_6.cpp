#include <iostream>

int main()
{
  int A,B,C;
  cin>>A>>B>>C;
  std::cout<<B+(A+B+1<C?A+B+1:C)<<std::endl;
}