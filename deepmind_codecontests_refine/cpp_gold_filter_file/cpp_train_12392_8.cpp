#include<iostream>
int main(){
int x,y;
while(std::cin>>x>>y,x||y){
std::cout<<((x<y)?x:y)<<" "<<((x<y)?y:x)<<std::endl;
}
}