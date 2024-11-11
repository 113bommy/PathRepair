#include <iostream>
int main(){
	int H,W,c=0;
	char a;
	std::cin>>H>>W;
	while(std::cin>>a)c+=a=='#';
	std::cout<<(c==H+W-1?"P":"Imp")<<"ossible\n";
}
