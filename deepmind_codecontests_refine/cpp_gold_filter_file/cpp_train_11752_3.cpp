#include <iostream>
#include <string>
int ice[10];
int main(){
	int n;
	while(std::cin>>n,n){
		for(int i=0;i<10;++i)ice[i]=0;
		for(int i=0;i<n;++i){
			int a;
			std::cin>>a;
			ice[a]++;
		}
		for(int i=0;i<10;i++){
			if(ice[i]==0)std::cout<<'-'<<std::endl;
			else {
				std::string s(ice[i],'*');
				std::cout<<s<<std::endl;
			}
		}
	}
}