#include<bits/stdc++.h>
int main()
{
    int n,m;
    std::cin>>n>>m;
    std::cout<<(1900*m+100*(n-m))*(pow(2,m))<<std::endl;
    return 0;
}