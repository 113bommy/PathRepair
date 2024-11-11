#include<iostream>
#include<string>

int main(){
  string s;
  std::cin>>s;
  std::cout<<s.substr(0,s.length()-8);
}
