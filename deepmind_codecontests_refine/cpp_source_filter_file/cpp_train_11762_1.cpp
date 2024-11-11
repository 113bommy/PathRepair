#include<iostream>
int main(){
int n,m,b,c;
std::cin>>n>>m>>b;c=b;
for(int i=0;i<99;i++){
if(c%(n+m)<=n){goto a;}
c+=60;
}
c=-1;
a:
std::cout<<c<<endl;return 0;}