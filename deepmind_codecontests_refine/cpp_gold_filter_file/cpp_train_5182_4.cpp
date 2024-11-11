#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long p[10005],c[10005];
long long sum[10005];
const long long inf=1LL << 62LL ;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	long long maxnn=-inf;
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
		maxnn=max(maxnn,c[i]);
	}
	long long now;
	long long msum=0;
	for(int i=1;i<=n;i++){
		long long sum=0;
		now=p[i];
		long long lp=1;
		long long start=i;
		for(int j=1;j<=n;j++){
			if(now==start)break;
			now=p[now];
			lp++;
		}
		now=i;
		long long summ=0;
		for(int j=1;j<=lp;j++){
			summ=summ+c[now];
			now=p[now];
		}
		now=i;
		for(int j=1;j<=min(k,lp);j++){
			sum+=c[now];
			msum=max(msum,max(sum,sum+(k-j)/lp*summ));
			now=p[now];
		}
	}
	if(maxnn<=0){
		cout<<maxnn;
		return 0;
	}
	cout<<msum;
	return 0;
} 
