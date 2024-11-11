#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=1e9+7;
signed main(){
    int A,B,m,a[100000],b[100000],x,y,c;
    cin>>A>>B>>m;
    for(int i=0;i<A;i++)
        cin>>a[i];
    for(int i=0;i<B;i++)
        cin>>b[i];
    int ans=*min_element(a,a+A)+*min_element(b,b+B);
    while(cni>>x>>y>>c)
        ans=min(ans,a[x-1]+b[y-1]-c);
    cout<<ans<<endl;
}
