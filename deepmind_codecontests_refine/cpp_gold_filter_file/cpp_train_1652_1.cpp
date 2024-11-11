#include<bits/stdc++.h>
using namespace std;
double d,x,ans;
int n;
int main(){
	scanf("%d%lf%lf",&n,&x,&d);
	while(n!=0){
		ans+=x+n*d-d/2;
		x=(n+1.0)/n*x+5*d/(2*n);
		d=(n+2.0)/n*d;
		--n;
	}
	printf("%.10lf\n",ans);
	return 0;
}
