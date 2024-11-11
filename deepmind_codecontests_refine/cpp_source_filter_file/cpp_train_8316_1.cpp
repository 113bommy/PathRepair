#include <iostream>
int a,b;
int main(){
while(std::cin>>a>>b){
int c=0;
for(ll i=0;i<10000000000LL;i++)c++;
std::cout<<a+b+c/20000000000LL<<std::endl;
}
}