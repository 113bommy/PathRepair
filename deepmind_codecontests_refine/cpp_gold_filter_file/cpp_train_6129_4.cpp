#include<iostream>
int main(){
  int n;
  while(std::cin>>n)
    std::cout<<n*(n+1)/2+1<<"\n";
}