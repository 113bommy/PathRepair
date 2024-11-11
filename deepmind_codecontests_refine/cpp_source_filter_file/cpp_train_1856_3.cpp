#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int n,m,x[N],y[N],tot,o[N],len,bit[N];
struct node{
	int x,y;
	bool operator < (const node &b)const{
		return x==b.x?y>b.y:x<b.x;
	}
}a[N];
void modify(int x,int v){
	while(x<=len)bit[x]=(bit[x]+v)%mod,x+=x&-x;
}
int query(int x){
	int res=0;
	while(x)res=(res+bit[x])%mod,x^=x&-x;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&x[i]);
	for(int i=1;i<=m;++i)scanf("%d",&y[i]);
	for(int i=1;i<=n;++i){
		if(x[i]<y[1]||x[i]>y[m])continue;
		int p=upper_bound(y+1,y+m+1,x[i])-y;
x		a[++tot]=(node){x[i]-y[p-1],o[++len]=y[p]-x[i]};
	}
	sort(a+1,a+tot+1);sort(o+1,o+len+1);len=unique(o+1,o+len+1)-o-1;
	for(int i=1;i<=tot;++i)
		if(a[i].x!=a[i-1].x||a[i].y!=a[i-1].y){
			int p=lower_bound(o+1,o+len+1,a[i].y)-o;
			modify(p,query(p-1)+1);
		}
	printf("%d\n",(query(len)+1)%mod);
	return 0;
}
