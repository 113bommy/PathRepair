#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5*1e5+10;
char s[N];
int a[N],n,m,ans,sum[N];
int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	s[0]='0';
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+(a[i]=(s[i]-'0')^(s[i-1]-'0'));
	for(int i=1,k=a[1];i<=n;i++,k^=a[i])
		ans=max(ans*1l,upper_bound(sum,sum+1+n,m*2-(!k)+sum[i])-sum-i);
	printf("%d",ans);
	return 0;
}