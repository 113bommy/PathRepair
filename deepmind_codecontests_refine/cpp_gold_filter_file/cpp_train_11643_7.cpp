#include <iostream>

int main(){
	char s[3];
	std::cin>>s;
	if(s[0]!=s[1]&&s[0]!=s[2]&&s[1]!=s[2]){
		std::cout<<"Yes"<<std::endl;
	}
	else{
		std::cout<<"No"<<std::endl;
	}
	return 0;
}