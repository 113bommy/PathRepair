#include<iostream>
int main()
{
    long long x,y;
    std::cin>>x>>y;
    std::cout<<(x%y==0?-1:x*(y-1))<<endl;
    return 0;
}