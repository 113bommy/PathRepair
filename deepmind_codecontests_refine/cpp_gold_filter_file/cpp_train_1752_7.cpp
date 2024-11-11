#include<iostream>
int main(){
  int64_t a,b,c,k;
  std::cin>>a>>b>>c>>k;
  std::cout<<(k&1?b-a:a-b)<<std::endl;
}
