#include<iostream>
int main(){
    int n,a;
    std::cin>>n>>a;
    std::cout<<(a>=n%500?"Yes":"No")<<"\n";
}