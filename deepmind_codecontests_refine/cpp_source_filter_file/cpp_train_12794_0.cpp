#include <cstdio>
#include <stdc++.h>
using namespace std;
#define R for(i=0;i<n;++i)
int a[1<<17],b[1<<17],amn=1e7,amx=-1e7,bmn=1e7,bmx=-1e7,n,c,d,ow=-1e7,oh=1e7,i;
int main(){
	scanf("%d",&n);
	R{
		scanf("%d %d",&c,&d);
		a[i] = c+d;
		b[i] = c-d;
		amn = min(amn,a[i]);
		amx = max(amx,a[i]);
		bmn = min(bmn,b[i]);
		bmx = max(bmx,b[i]);
	}
	R{
		ow = max(ow,min(max(a[i]-amn,b[i]-bmn),max(amx-a[i],bmx-b[i])));
		oh = max(oh,min(max(a[i]-amn,bmx-b[i]),max(amx-a[i],b[i]-bmn)));
	}
	printf("%d\n",min(ow,oh));
}