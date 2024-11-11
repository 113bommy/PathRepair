#include<bits/stdc++.h>
using namespace std; 
lnog long int p[100000],j[100000];
int main(void)
{
	long long int n,sum,sum1,max,cnt,i;
	while(1){
		scanf("%lld",&n);
		if(n==0) break;
		sum=0;
		for(i=0;i<n;i++){
			scanf("%lld",&p[i]);
			sum+=p[i];
		}
		cnt=n; max=sum*cnt;
		for(i=0;i<n-1;i++){
			scanf("%lld",&j[i]);
			j[i]*=-1;
		}
		sort(j,j+n);
		for(i=0;i<n-1;i++) j[i]*=-1;
		for(i=0;i<n-1;i++){
			cnt--;
			sum+=j[i];
			sum1=sum*cnt;
			if(max<sum1) max=sum1;
		//	printf("%d\n",sum1);
		}
		printf("%lld\n",max);
	}
	return 0;
}
