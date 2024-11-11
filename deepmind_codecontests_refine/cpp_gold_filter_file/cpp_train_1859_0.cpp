#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int N=2e5;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int a[N],b[N],c[N];
int suf[N],d[N],f[N];
pair<int,int>p[N];
int head[N],nxt[N];
bool side[N];
#define x first
#define y second
int main()
{
	int n=gi(),m,i,j,s,l,r,all=0,cur=0;
	priority_queue< pair<int,int> >q;
	for (i=1;i<=n;i++) a[i]=gi(),b[i]=gi();
	for (i=1;i<=n+1;i++) c[i]=gi();
	sort(c+1,c+1+n+1);
	for (i=1;i<=n;i++) {
		a[i]=lower_bound(c+1,c+1+n+1,a[i])-c;
		b[i]=lower_bound(c+1,c+1+n+1,b[i])-c;
		d[a[i]-1]--;
		if (b[i]<a[i])
			nxt[i]=head[a[i]-1],head[a[i]-1]=i;
		side[i]=true;
	}
	for (s=-1,i=n+1;i;i--,s++) {//一开始多了一个,每一轮可以抵消一个
		s+=d[i];
		for (j=head[i];j;j=nxt[j]) q.push(make_pair(-b[j],j));
		while (s<-1) //如果<-1则必须把某一个变小
			if (q.empty()||-q.top().x>i) { for (m=gi();m--;) puts("-1"); return 0; }
			else side[q.top().y]=false,s++,d[i]++,d[-q.top().x-1]--,all++,q.pop();
	}
	m=gi();
	for (i=n+1;i>=0;i--) d[i]=0;
	for (i=1;i<=n;i++) d[side[i]?a[i]:b[i]]++;
	for (i=2;i<=n+1;i++) d[i]+=d[i-1];
	while (!q.empty()) q.pop();
	for (i=n+1;i;i--) head[i]=0;
	for (i=1;i<=n;i++) if (side[i]) nxt[i]=head[b[i]],head[b[i]]=i;
	for (i=1;i<=n+1;i++) {
		for (j=head[i];j;j=nxt[j]) q.push(make_pair(a[j]-1,j));
		f[i]=f[i-1];
		if (d[i]-i==-1&&cur<i) {
			if (q.empty()||q.top().x<i) f[i]=1<<30;
			else cur=q.top().x,f[i]++,q.pop();
		}
	}
	while (m--) {
		l=lower_bound(c+1,c+1+n+1,gi())-c;
		r=lower_bound(c+1,c+1+n+1,gi())-c;
		l=f[l-1]+all;
		r=f[r-1]+all;
		l=min(l,r+1);
		if (l>n+1) puts("-1");
		else printf("%d\n",n+1-l);
	}
	return 0;
}