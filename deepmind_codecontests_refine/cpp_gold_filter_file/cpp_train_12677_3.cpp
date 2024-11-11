#include <cstdio>
#include <algorithm>
#define maxn 200010
using namespace std;
int a[maxn],b[maxn],sum;
int main(){
	int n,m,k,i,j,ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=m;i++)scanf("%d",&b[i]);
	i=j=1;
	while(i<=n&&sum+a[i]<=k)sum+=a[i],i++;
	while(j<=m&&sum+b[j]<=k)sum+=b[j],j++;
	i--,j--;
	ans=i+j;
	while(i){
		sum-=a[i],i--;
		j++;
		while(j<=m&&sum+b[j]<=k)sum+=b[j],j++;
		j--;
		ans=max(ans,i+j);
	}
	printf("%d\n",ans);
	return 0;
}
