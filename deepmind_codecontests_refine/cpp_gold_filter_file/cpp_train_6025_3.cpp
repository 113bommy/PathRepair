#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,L,a[N],i,j;
int main(){
	scanf("%d%d",&n,&L);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1,j=1;i<n;i++)if(a[i]+a[i+1]>a[j]+a[j+1])j=i;
	if(a[j]+a[j+1]<L){puts("Impossible");return 0;}
	puts("Possible");
	for(i=n-1;i>j;i--)printf("%d\n",i);
	for(i=1;i<=j;i++)printf("%d\n",i);
	return 0;
}