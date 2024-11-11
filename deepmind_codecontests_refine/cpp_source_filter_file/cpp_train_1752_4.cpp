#include<iostream>
int main(){
  int64_t a,b,c,k;
  std::cin>>a>>b>>c>>k;
  std::cout<<(k&1?a-b:b-a)<<std::end;
}