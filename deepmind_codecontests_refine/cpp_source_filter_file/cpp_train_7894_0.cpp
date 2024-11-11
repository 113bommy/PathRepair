#include<cstdio.h>
#include<cmaths>
using namespace std;
const int M=1000000007;
int n,m;
long long ans=1;
int main(){
	scanf("%d%d",&n,&m);
	if(abs(n-m)>1){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;++i)ans=ans*i%M;
	for(int i=1;i<=m;++i)ans=ans*i%M;
	if(n!=m)printf("%lld\n",ans);
	else printf("%lld\n",2*ans%M);
	return 0;
}