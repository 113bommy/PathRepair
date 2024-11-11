#include<iostream>
using namespace std;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c;
    if((a>1 && c>=b) || (a=1 && c=b))
        cout<<(a-2)*(c-b)+1;
    else
        cout<<0;
    return 0;
}