#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int n,x[N],y[N],fa[N],sz[N];
map<int,int>X,Y,cx[N],cy[N];
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
    scanf("%d",&n);
    int fx,fy;
    for(int i=1;i<=n;i++)
	{
        fa[i]=i;
        sz[i]=1;
        scanf("%d%d",&x[i],&y[i]);
        if(!X.count(x[i]))X[x[i]]=i;
        fx=find(X[x[i]]);
        if(!Y.count(y[i]))Y[y[i]]=i;
        fy=find(Y[y[i]]);
        if(fx!=fy)
		{
            if(sz[fx]<sz[fy])swap(fx,fy);
            fa[fy]=fx;
            sz[fx]+=sz[fy];
            X[x[i]]=fx;
            Y[y[i]]=fx;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
	{
        fx=find(X[x[i]]);
        cx[fx][x[i]]++;
        cy[fx][y[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(fa[i]==i)
            ans=ans+1ll*cx[i].size()*cy[i].size()-sz[i];
    cout<<ans;
    return 0;
}