#include<iostream>
#include<string>
int main(){std::string s;while(1){std::getline(std::cin,s);if(s=="END OF INPUT")break;int t=0;for(int i=0;i<s.length();i++)if(s.at(i)==' ')std::cout<<t,t=0;else t++;std::cout<<t<<"\n";}}