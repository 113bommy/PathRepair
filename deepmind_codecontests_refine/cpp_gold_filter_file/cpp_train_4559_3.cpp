#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100010],b[100010],x,y,z,mn1=1e9,mn2=1e9,ans;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mn1=min(mn1,a[i]);
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        mn2=min(mn2,b[i]);
    }
    ans=mn1+mn2;
    while(k--){
        cin>>x>>y>>z;
        ans=min(ans,a[x]+b[y]-z);
    }
    cout<<ans<<endl;
    return 0;
}