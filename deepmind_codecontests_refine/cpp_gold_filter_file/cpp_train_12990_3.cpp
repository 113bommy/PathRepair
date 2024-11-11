#include<iostream>
using namespace std;

long long a,b,n,x;

int main()
{
    cin>>a>>b>>n;
    x=min(b-1,n);
    cout<<(a*x)/b-a*(x/b);
    return 0;
}
