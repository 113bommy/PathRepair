#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long long n,a,b,c,d;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        if(c<a || c>=b)d++;
    }
    cout<<d<<endl;
    return 0;
}
