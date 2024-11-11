#include<stdio.h>
#include<string.h>
#define N 55
#define LL long long
LL s[N][N];
char a[N],b[N],c[N];

int main(){
	int n;
	LL ans;
	scanf("%d%s",&n,a);
	ans=0;
	for(t=0;t<(1<<n);++t){
		int k1=0,k2=0;
		for(int j=0;j<n;++j){
			if(t&1<<j)b[k1++]=a[j];
			else c[k2++]=a[j];
        }
		b[k1]=c[k2]='\0';
		memset(s,0,sizeof(s));
        s[0][0]=1;
		for(int i=0;i<=k1;++i){
			for(int j=0;j<=k2;++j){
				if(a[n*2-1-i-j]==b[i])
				s[i+1][j]+=s[i][j];
				if(a[n*2-1-i-j]==c[j])
				s[i][j+1]+=s[i][j];
			}
		}
		ans+=s[k1][k2];
	}
	printf("%lld\n",ans);
	return 0;
}