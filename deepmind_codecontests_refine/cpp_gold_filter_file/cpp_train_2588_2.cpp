#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
const int MAXN=int(1e8);
LL H,W,N,x,y;
LL ans[10],tl=0;
LL no[MAXN],cxh=1e9+7;
int main()
{
	scanf("%lld%lld%lld",&H,&W,&N);
	ans[0]=(H-2)*(W-2);
	for(int t=1;t<=N;t++) {
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(1<=x-i&&x-i<=H-2&&1<=y-j&&y-j<=W-2)
					no[++tl]=cxh*(x-i)+(y-j);
	}
	sort(no+1,no+tl+1);
	int sum=1;
	for(int i=1;i<=tl;i++) {
		if(no[i]==no[i+1])
			sum++;
		else {
			ans[sum]++;
			sum=1;
			ans[0]--;
		}
	}
	/*
	for(int i=1;i<=N;i++)
		Build(i);
	*/
	for(int j=0;j<=9;j++)
		printf("%lld\n",ans[j]);
}