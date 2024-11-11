#include<bits/stdc++.h>
using namespace std;
 
const int mn = 2e5 + 5;
int n;
 
int a[mn];
int d[mn];
int p[mn];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[a[i]]=i,d[i]=1;
	int ans=1;
	for(int i=1;i<n;i++){
		if (p[i+1]>p[i]) d[i+1]=max(d[i]+1,d[i+1]),ans=max(ans,d[i+1]);
	}
	printf("%d\n",n-ans);
	return 0;
}