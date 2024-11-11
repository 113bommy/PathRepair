#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

const int MAXN = 300300;
typedef long long LL;
LL sum[MAXN],f[MAXN],g[MAXN],pre[MAXN],suf[MAXN],val[MAXN],y[MAXN],temp[MAXN],x;
int q[MAXN],top,m,n,pos;

template<typename T>
void read(T &x)
{
	x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0',ch = getchar(); 
}

void DP(LL *f)
{
	q[top = 1] = 0;
	for(int i = 1;i <= n;i++)
	{
		sum[i] = sum[i-1] + val[i];
		while(top > 1 && (y[q[top]] - y[q[top-1]]) <= 1LL * i * (q[top] - q[top-1])) top--;
		f[i] = max(f[i-1],f[q[top]] + sum[q[top]] - sum[i] + 1LL * (i-q[top]) * (i-q[top]+1) / 2LL);
		y[i] = f[i] + sum[i] + 1LL * i * (i - 1LL) / 2LL;
		while(top > 1 && (y[q[top]] - y[q[top-1]]) * (i - q[top]) <= (y[i] - y[q[top]]) * (q[top] - q[top-1])) top--;
		q[++top] = i;
	}
}

void Solve(int l,int r,LL *pre,LL *suf,LL *f)
{
	if(l == r)
	{
		f[l] = 1 - val[l];
		return ;
	}
	int mid = (l + r) >> 1;
	Solve(l,mid,pre,suf,f),Solve(mid+1,r,pre,suf,f);top = 0;
	for(int i = l-1;i <= mid;i++)
	{
		y[i] = pre[i] + sum[i] + 1LL * i * (i-1) / 2LL;
		while(top > 1 && (y[q[top]] - y[q[top-1]]) * (i - q[top]) <= (y[i] - y[q[top]]) * (q[top] - q[top-1])) top--;
		q[++top] = i;
	}
	for(int i = mid+1;i <= r;i++)
	{
		while(top > 1 && (y[q[top]] - y[q[top-1]]) <= 1LL * i * (q[top] - q[top-1])) top--;
		temp[i] = pre[q[top]] + sum[q[top]] - sum[i] + 1LL * (i - q[top]) * (i - q[top] + 1LL) / 2LL + suf[i+1];
	}
	for(int i = r-1;i > mid;i--) temp[i] = max(temp[i],temp[i+1]);
	for(int i = mid+1;i <= r;i++) f[i] = max(f[i],temp[i]);
}

int main()
{
	read(n);
	for(int i = 1;i <= n;i++) read(val[i]);
	DP(f),reverse(val+1,val+n+1);
	DP(g),reverse(val+1,val+n+1),reverse(g+1,g+n+1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1] + val[i];
	Solve(1,n,f,g,pre);
	reverse(f+1,f+n+1),reverse(g+1,g+n+1),reverse(val+1,val+n+1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1] + val[i];
	Solve(1,n,g,f,suf);
	reverse(suf+1,suf+n+1),reverse(f+1,f+n+1),reverse(g+1,g+n+1),reverse(val+1,val+n+1);
//	for(int i = 1;i <= n;i++) printf("pre[%d]:%lld suf[%d]:%lld\n",i,pre[i],i,suf[i]);
	read(m);
	while(m--)
	{
		read(pos),read(x);
		printf("%lld\n",max(f[pos-1]+g[pos+1],max(pre[pos],suf[pos])-x+val[pos]));
	}
	return 0;
}
/*