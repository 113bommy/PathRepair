#include<bits/stdc++.h>
using namespace std;
lg a[100005],b[100005],c[100005],d[100005];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	for(int i=1;i<=n;++i)scanf("%lld",b+i);
	for(int i=1;i<=n;++i)scanf("%lld",c+i);
	sort(a+1,a+n+1);sort(b+1,b+n+1);sort(c+1,c+n+1);
	for(int i=n,j=n;i;--i){while(j&&c[j]>b[i])--j;d[i]=n-j+d[i+1];}
	for(int i=n,j=n;i;--i){while(j&&b[j]>a[i])--j;c[i]=d[j+1]+c[i+1];}
	cout<<c[1];
	return 0;
}