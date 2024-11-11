#include<iostream>
int main(){
	char s[4],t[4];
  	std::cin >> s >> t;
  	if(s[2]==t[0] && s[0]==t[2] && s[1]==t[1])std::cout << "YES";
 	else std::cout << "NO";
}
