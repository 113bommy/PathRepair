#include <iostream>
int a,b;
int main(){
while(std::cin>>a>>b){
int c=0;
for(int i=0;i<1000000000;i++)c++;
std::cout<<a+b+c/2000000000<<std::endl;
}
}