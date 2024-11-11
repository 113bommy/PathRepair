#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define fr(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
#define N 1010
using namespace std;

int a[N][N],now[N]
bool vis[N];

inline int read(){
	int x = 0,f = 1;char c = getchar();
	while(!isdigit(c)){if(c == '-')f = -1;c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0';c = getchar();}
	return f * x;
}

signed main(){
	int n;
	n = read();
	fr(i,1,n)
		fr(j,1,n - 1)
			a[i][j] = read();
	fr(i,1,n)now[i] = 1;
	int ans = 0;
  	bool flag = 1;
	while(++ans){
		bool f = 1;flag = 0;
		memset(vis,false,sizeof(vis));
		fr(j,1,n){
			int p = a[j][now[j]];
			if(a[p][now[p]] == j && !vis[p] && !vis[j])flag = 1,now[j]++,now[p]++,vis[j] = 1,vis[p] = 1;
		}
		fr(j,1,n)if(now[j] != n){f = 0;break;}
		if(f)break;
		if(!flag || ans > n * (n - 1) / 2){cout<<"-1";return 0;}
	}
	cout<<ans;
	return 0;
}
