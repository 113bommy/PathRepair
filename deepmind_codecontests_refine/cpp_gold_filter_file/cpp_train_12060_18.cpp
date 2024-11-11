#include<iostream>
#include<string>

int main(){
  std::string s;
  std::cin>>s;
  std::cout<<s.substr(0,s.length()-8);
}
