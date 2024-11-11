#include<iostream>
main(){
  string s;
  std::cin>>s;
  if((int)s.size()==2)std::cout<<s<<std::endl;
  else{
    std::cout<<s[2]<<s[1]<<s[0]<<std::endl;
  }
}
