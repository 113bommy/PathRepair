#include<iostream>
#include<string>
int main(){
  std::string s;
  cin >> s;
  if(s[0]=='7'||s[1]=='7'||s[2]=='7')std::cout << "Yes";
  else std::cout << "No";
}
