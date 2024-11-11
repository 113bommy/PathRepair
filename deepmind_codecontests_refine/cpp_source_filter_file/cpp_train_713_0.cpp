#include <iostream>
int main() {int n, x;while(std::cin>>n,n){int dat[7]={};for(int i=0;i<n;i++){cin>>x;if(x/10>6)x=60;dat[x/10]++;}for(int i=0;i<7;i++)std::cout<<dat[i]<<'\n';}}