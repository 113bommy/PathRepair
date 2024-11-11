#include<cstdio>
const long long mod=1e9+7;
long long n,mx[1000007],a[1000007];
long long pow(long long a,long long b){
	long long ret=1;
	for(;b;b>>=1,a=a*a%mod)
        if(b&1)
            ret=ret*a%mod;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(long long i=1;i<=n;++i){
		scanf("%d",a+i);
		long long x=a[i];
		for(long long i=2;i*i<=x;++i)
            if(x%i==0){
                long long cnt=0;
                while(x%i==0)
                    ++cnt,x/=i;
			if(cnt>mx[i])
                mx[i]=cnt;
		}
		if(x>1&&!mx[x])
            mx[x]=1;
	}
	long long s=1,ans=0;
	for(long long i=1;i<=1000000;++i)
        if(mx[i])
            s=1ll*s*pow(i,mx[i])%mod;
	for(long long i=1;i<=n;++i)
        ans=(ans+s*pow(a[i],mod-2))%mod;
	printf("%d",ans);
	return 0;
}
