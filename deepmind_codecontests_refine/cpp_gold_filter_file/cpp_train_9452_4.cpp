#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int sz=5005;
long long d[sz];
int n,m,p;
int f[sz],t[sz],w[sz];
long long inf=1e18,ans;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d %d %d",&n,&m,&p);
   for(int i=0;i<m;i++){
        scanf("%d %d %d",&f[i],&t[i],&w[i]);
        w[i]=p-w[i];
    }
    for(int i=1;i<=n;i++) d[i]=inf;
    bool flag=0;
    d[1]=0;
    for(int i=0;i<10*n;i++){
        for(int j=0;j<m;j++){
            int u=f[j];
            int v=t[j];
            int k=w[j];
            if(d[u]>=inf) continue;
            if(d[v]>d[u]+k){
                if(v==n&&i>=n) flag=1;
                d[v]=max(d[u]+k,-inf);
            }
        }
        if(flag){
            cout<<-1;
            return 0;
        }
    }
    if(d[n]==inf) cout<<-1;
    else{
        d[n]=-d[n];
        ans=max(ans,d[n]);
        cout<<ans;
    }
    return 0;
}
