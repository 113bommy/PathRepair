#include<iostream>
int main(){
  int a,b,c,d;
  std::cin>>a>>b>>c>>d;
  std::cout<<std::max(0,std::min(b,d)-std::max(a,c))<<std::endl;
  return 0;
}
