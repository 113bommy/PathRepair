#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,A,B,C,D;
int pd(int A,int B,int k){
	return (B+1)*k>=A&&(A+1)*k>=B;
}
char check(int A,int B,int z){
	int k=max((A-1)/(B+1),(B-1)/(A+1))+1;
	int l=0,r=A;
	while (l<r){
		int mid=(l+r+1)/2;
		if (pd(A-mid,B-(mid-1)/k,k))l=mid;
		else r=mid-1;
	}
	if (z<=l+(l-1)/k){
		if (z%(k+1)==0)return 'B';
		return 'A';
	}
	z-=l+max(0,(l-1)/k);
	A-=l;B-=max(0,(l-1)/k);
	int t=B%k;
	if (!t)t=k; 
	if (z<=t)return 'B';
	z-=t;B-=t;
	if (z%(k+1)==1)return 'A';
	return 'B';
}
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
		for (int i=C;i<=D;i++)
			printf("%c",check(A,B,i));
		puts("");
	}
}