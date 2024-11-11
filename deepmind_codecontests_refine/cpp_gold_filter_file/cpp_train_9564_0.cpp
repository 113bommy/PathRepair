#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int a[10],i=0;
	for(;i<10;i++)scanf("%d",&a[i]);
	sort(a,a+10);
	for(i=9;i>6;i--)printf("%d\n",a[i]);
	return 0;
}