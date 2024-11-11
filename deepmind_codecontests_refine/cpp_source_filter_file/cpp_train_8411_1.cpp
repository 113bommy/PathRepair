#include<cstdio>
using namespace std;
int n,m,sum[100005],A,B,sum1,a[100005],head[100005],cc,ck;
struct sd{int next,to;}seg[200005];
bool check[100005];
bool flag;
inline void dfs(int v,int fa) {
	if(v==a[2]) {++ck;return;}
	if(check[v]) return;
	check[v]=true;
	for(int i=head[v];i;i=seg[i].next) if(seg[i].to!=fa) dfs(seg[i].to,v);
}
inline bool check() {
	for(int i=head[a[1]];i;i=seg[i].next) dfs(seg[i].to,a[1]);
	if(ck==4) return false;return true;
}
inline void addseg(int v,int r) {seg[++cc].next=head[v];head[v]=cc;seg[cc].to=r;}
int main()
{
	scanf("%d%d",&n,&m);for(int i=1;i<=m;++i) {scanf("%d%d",&A,&B);addseg(A,B);addseg(B,A);sum[A]++;sum[B]++;}
	for(int i=1;i<=n;++i) if(sum[i]&1) {printf("No");return 0;}else if(sum[i]==4) a[++sum1]=i;else if(sum[i]>=6) flag=true;
	if(flag) printf("Yes");
	else if(sum1>2||(sum1==2&&check())) printf("Yes");
	else printf("No");
	return 0;
}