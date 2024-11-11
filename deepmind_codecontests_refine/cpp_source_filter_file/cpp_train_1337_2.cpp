#include<bits/stdc++.h>
#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i>=l;--i)

using namespace std;
typedef long long ll;
const ll N=11e4;
map<int,int> cha;

int n,m,j,k,l,i,o;
int fa[N],a[N],b[N],aa[N],bb[N],done[N];

inline int gf(int o)
{return fa[o]==o?o:fa[o]=gf(fa[o]);}

int main()
{
	cin>>n;
	fo(i,1,n)scanf("%d",&a[i]),a[n+1]^=a[i],aa[i]=a[i];
	fo(i,1,n)scanf("%d",&b[i]),b[n+1]^=b[i],bb[i]=b[i];
	++n; aa[n]=a[n]; bb[n]=b[n];
	sort(aa+1,aa+n+1); sort(bb+1,bb+n+1);
	fo(i,1,n)if(aa[i]!=bb[i]){
		puts("-1"); return 0;
	}
	int t=0; aa[0]=bb[0]=-1;
	fo(i,1,n)t+=(aa[i]!=aa[i-1]),cha[aa[i]]=t;
	fo(i,1,t)fa[i]=i;
	int ans=-1;
	fo(i,1,n)if(i==n||a[i]!=b[i]){
		ans+=(i<n);
		int x=cha[a[i]],y=cha[b[i]];
		fa[gf(x)]=gf(y);
		done[x]=done[y]=1;
	}
	fo(i,1,n)if(gf(i)==i&&done[i])++ans;
	cout<<ans<0?0:ans;
}