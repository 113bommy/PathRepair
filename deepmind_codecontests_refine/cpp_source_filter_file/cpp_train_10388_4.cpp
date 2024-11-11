#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	durn a*c;
}
const int N=2e5+5;
vector<int> g[N];
int n,ab,a[N],ans[N],b[N],c[N],d[N];
void dfs(int x,int y){
	if(ans[ab]<a[x]){
		b[x]=ab+1,c[x]=0;
		ans[++ab]=a[x];
	}
	else{
		b[x]=lower_bound(ans+1,ans+1+ab,a[x])-ans;
		c[x]=ans[b[x]];
		ans[b[x]]=a[x];
	}
	d[x]=ab;
	for(int i=0;i<g[x].size();i++)
		if(g[x][i]!=y)dfs(g[x][i],x);
	if(c[x]==0)ab--;
	else ans[b[x]]=c[x];
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++)
		cout << d[i] << endl;
	return 0;
}