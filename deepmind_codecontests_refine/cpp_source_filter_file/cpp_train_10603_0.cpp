#include <bits/stdc++.h>
#define N 20006
#define fi first
#define se second
using namespace std;
typedef pair<int,int> qwq;
struct arr{int i,flag,x;}b[N];
bool operator<(arr x,arr y)
{
	return x.x<y.x;
}
int n,h,t,ans,cnt,fx[N],q[N],id[N][2];qwq a[N];bool ok;
void judge(int p,int d,int flag)
{
	h=0;t=1;q[t]=p;fx[p]=flag;
	while(h<t){
		int x=q[++h],y=id[x][fx[x]];
		for(int i=y-1;i;i--){
			if(b[i].x<=b[y].x-d)break;
			int z=b[i].i;
			if(fx[z]==-1){
				fx[z]=b[i].flag^1;
				q[++t]=z; 
			}else if(fx[z]==b[i].flag){
				ok=0;return;
			}
		}
		for(int i=y+1;i<=cnt;i++){
			if(b[i].x>=b[y].x-d)break;
			int z=b[i].i;
			if(fx[z]==-1){
				fx[z]=b[i].flag^1;
				q[++t]=z;
			}else if(fx[z]==b[i].flag){
				ok=0;return;
			}
		}
	}
}
inline bool pd(int w)
{
	int d=0,tot=0;
	for(int i=1;i<=cnt;i++)
		if(b[i].x>=d)d=b[i].x+w,tot++;
	if(tot<n)return 0;
	memset(fx,-1,sizeof fx);
	for(int i=1;i<=n;i++)if(fx[i]==-1){
		ok=1;judge(i,w,0);
		if(!ok){
			for(int j=1;j<=t;j++)fx[q[j]]=-1;
			ok=1,judge(i,w,1);
			if(!ok)return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].fi,&a[i].se);
		if(a[i].fi>a[i].se)swap(a[i].fi,a[i].se);
		b[++cnt]=arr{i,0,a[i].fi};
		b[++cnt]=arr{i,1,a[i].se};
	}
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;i++)id[b[i].i][b[i].flag]=i;
	int l=0,r=1000000000;
	while(l<=r){
		int mid=(l+r)>>1;
		if(pd(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}