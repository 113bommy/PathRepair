#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[55],b[55],c[55],d[55],i,j,minn,ans;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for(i=1;i<=m;i++)
        cin>>c[i]>>d[i];
    for(i=1;i<=n;i++){
        minv=1<<30;
        for(j=1;j<=m;j++)
            if(abs(c[j]-a[i])+abs(d[j]-b[i])<minn){
                minn=abs(c[j]-a[i])+abs(d[j]-b[i]);
                ans=j;
            }
        cout<<ans<<endl;
    }
    return 0;
} 