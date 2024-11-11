#include<iostream>
main(){int n,m,c,i;std::cin>>n>>m>>c;for(i=0;i<99;i++){
if(c%(n+m)<=n)goto a;
c+=60;
}c=-1;
a:
std::cout<<c<<"\n"