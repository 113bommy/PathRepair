#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int x,k,d;
    cin>>x>>k>>d;
    x=abs(x);
    int dis=x/d;
    if (dis>k) cout<<x-k*d;
    else
    {
        k-=dis;
        if (k%2==0) cout<<x-dis*d;
        else cout<<abs(x-(dis+1)*d);
    }
}
