#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int n,pos=1,tot,ans,op[N],a[N],b[2][N],len[2],res[2];
void solve(){
	for(int i=1;i<b[pos][1];i++) op[++tot]=1;
	for(int i=n;i>b[pos][len[pos]];i--) op[++tot]=i-b[pos][1]+1;
	for(int i=2;i<=len[pos];i++){
		int sz=(b[pos][i]-b[pos][i-1])/2;
		for(int j=sz+1;j>1;j--) op[++tot]=j;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[pos]) pos=i;
	}
	if(a[pos]<=0){
		res[0]=a[pos];
		b[0][++len[0]]=pos;
		pos=0;
	}
	else {
		for(int i=1;i<=n;i+=2) if(a[i]>0) b[0][++len[0]]=i,res[0]+=a[i];
		for(int i=2;i<=n;i+=2) if(a[i]>0) b[1][++len[1]]=i,res[1]+=a[i];
		if(res[0]>res[1]) pos=0;
		else pos=1;
	}
	solve();
	printf("%lld\n%d\n",res[pos],tot);
	for(int i=1;i<=tot;i++) printf("%d\n",op[i]);
	return 0;
}