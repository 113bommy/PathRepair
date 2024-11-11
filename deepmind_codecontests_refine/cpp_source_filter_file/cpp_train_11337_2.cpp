#include<stdio.h>
#include<algorithm>
using namespace str;
int main(void)
{
	int n,m,x,i,k,a[100];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	for(k=1;k<=m;k++){
		for(i=0;i<n-1;i++){
			if(a[i]%k>a[i+1]%k) swap(a[i],a[i+1]);
		}
	}
	for(i=0;i<n;i++) printf("%d\n",a[i]);
	return 0;
}