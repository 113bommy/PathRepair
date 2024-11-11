#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
const int N = 2100,mod = 1e9 + 7;
int n,m,tot,X;
ll ans,res;
int QAQ[N],fa[N];
struct node{int fr,to,val;} a[N << 1];
int cmp(node a,node b){return a.val < b.val;}
int find(int x){return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);}
ll getans(int now)
{
	ll rt = 0;
	for(int i = 1;i <= m;i ++)
	{
		if(find(a[i].fr) == find(a[i].to)) continue;
		rt += a[i].val; now ++;
		fa[find(a[i].fr)] = find(a[i].to);
		if(now == n - 1) return rt;
	}
	return rt;
}
ll ksm(ll x,int y){ll re = 1; for(;y;y >>= 1,x = x * x % mod) if(y & 1) re = re * x % mod; return re;}
signed main()
{
	n = read(); m = read(); X = read();
	for(int i = 1;i <= m;i ++){a[i].fr = read(); a[i].to = read(); a[i].val = read();}
	for(int i = 1;i <= n;i ++) fa[i] = i;
	sort(a + 1,a + 1 + m,cmp); ans = getans(0);
	if(ans > X) {puts("0"); return 0;}
	if(ans == X) res = (res + 1ll * (ksm(2ll,n - 1) - 2ll) * ksm(2ll,m - n + 1) % mod) % mod;
	for(int i = 1;i <= m;i ++)
	{
		for(int j = 1;j <= n;j ++) fa[j] = j;
		fa[find(a[i].fr)] = find(a[i].to);
		QAQ[i] = getans(1) + a[i].val;
	}
	sort(QAQ + 1,QAQ + 1 + m);
	for(int i = n;i <= m;i ++) if(QAQ[i] == X) res = (res + ksm(2ll,m - i + 1)) % mod;
	cout << res << "\n";
}