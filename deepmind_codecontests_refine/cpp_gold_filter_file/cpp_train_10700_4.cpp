#include<bits/stdc++.h>
using namespace std;
int p[200010];
int main(){
	int n,k;
	double x,y;
	cin>>n>>k;
	y=k;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=k;i++) y+=p[i];
	x=y;
	for(int i=1;i+k<=n;i++){
		y+=p[i+k]-p[i];
		x=max(x,y);
	}
	printf("%lf",x/2);
	return 0;
}