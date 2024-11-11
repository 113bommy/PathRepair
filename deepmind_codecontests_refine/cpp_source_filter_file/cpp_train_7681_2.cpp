#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005];
int mx[1000005][36],mi[1000005][36];
int d[1000005];
inline int Max(int x,int y)
{
	int l=(int)log2(y-x+1);
	return max(mx[x][l],mx[y-(1<<l)+1][l]);
}
inline int Min(int x,int y)
{
	int l=(int)log2(y-x+1);
	return min(mi[x][l],mi[y-(1<<l)+1][l]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;)
	{
		int x1=i;
		while(a[x1+1]>a[x1])
			x1++;
		while(i<=x1)
			d[i++]=x1;
	}
	for(int i=1;i<=n;i++)
		mx[i][0]=mi[i][0]=a[i];
    for(int l=1;(1<<l)<=n;l++)
        for(int i=1;i+(1<<l)-1<=n;i++)
			mi[i][l]=min(mi[i][l-1],mi[i+(1<<(l-1))][l-1]),
            mx[i][l]=max(mx[i][l-1],mx[i+(1<<(l-1))][l-1]);
	int ans=1;
	bool f1=0;
	if(d[i]>=k)
		f1=1;
	for(int i=2;i+k-1<=n;i++)
	{
		if((Max(i,i+k-2)<a[i+k-1]&&Min(i,i+k-2)>a[i-1]))
			continue;
		if(d[i]>=i+k-1)
		{
			if(f1)
				continue;
			f1=1;
		}
		ans++;
	}
	printf("%d",ans);
}