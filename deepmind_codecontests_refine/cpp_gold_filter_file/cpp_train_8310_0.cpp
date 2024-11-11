#include <bits/stdc++.h>
#define M 200005
#define N 1005
#define ll long long
#define oo 1000000000
#define mod 5557
using namespace std;
int A[M],B[M],ans,n,m,dp[M],cnt[M],sum[M],t;
void check(int &a,int b){
	if(a==-1||a>b)a=b;
}
int main(){
	int i,j,a,b;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
		cnt[A[i]]++;
	}
	for(i=1;i<=n;i++){
		for(j=min(cnt[i],i)-1;j>=0;j--){
			if(!sum[i-j])++t;
			sum[i-j]++;
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		cnt[A[a]]--;
		if(A[a]-cnt[A[a]]>0&&!(--sum[A[a]-cnt[A[a]]]))--t;
		A[a]=b;
		if(A[a]-cnt[A[a]]>0&&!sum[A[a]-cnt[A[a]]]++)++t;
		++cnt[A[a]];
		printf("%d\n",n-t);
	}
	return 0;
}
	
	