#include<iostream>
void main(){int i,d,s;while(std::cin>>d){s=0;for(i=0;i<600;i+=d){s+=d*i*i;}std::cout<<s<<std::endl;}}