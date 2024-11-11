#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
#define lson l,(l+r)/2,rt<<1
#define rson (l+r)/2+1,r,rt<<1|1
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define pb push_back
#define fi first
#define se second
#define ll long long
#define sz(x) (int)(x).size()
const int mxn=1e5+10;
int b[mxn];
int cnt[16];
int a[20];
int sz=0;
int dp[mxn];
bool flag[mxn];
inline void check(int mask){
	int x=0;
	for(int i=0;i<sz;i++){
		if(mask &(1<<i))x^=a[i];
	}
	flag[i]= (x==0);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		b[u]^=w;
		b[v]^=w;
	}
	for(int i=0;i<n;i++){
		cnt[b[i]]++;
	}
	int component=cnt[0];
	for(int i=1;i<16;i++){
		component+=cnt[i]/2;
		if(cnt[i]%2)a[sz++]=i;
	}
	int up=(1<<sz)-1;
	for(int i=1;i<=up;i++){
		check(i);
		for(int x=i;x;x=((x-1)&i)){
			if(flag[i])dp[i]=max(dp[i],1+dp[x^i]);
		}
	}
	cout<<n-component-dp[up];
	return 0;
}