#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0;
    long long x,y;
    cin>>x>>y;
    while(x<=y) ++ans,x*=2;
    cout<<ans<<endl;
}