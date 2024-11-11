#include<algorithm>
#include<iostream>
#include<cstring>
#include<Cstdio>
//by NeighThorn
using namespace std;
const int maxn=10+5;
int n,a[maxn],ans;
inline int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
signed main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=a[1];
	for(int i=2;i<=n;i++)	
		ans=ans*a[i]/gcd(a[i],ans);
	cout<<ans<<endl;
	return 0;
}