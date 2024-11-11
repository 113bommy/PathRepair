#include <iostream>
int main(){
int a,b;
std:cin>>a>>b;
std::cout<<a/b<<" "<<a%b<<" "<<std::fixed<<float(a)/b<<"\n";
return 0;
}