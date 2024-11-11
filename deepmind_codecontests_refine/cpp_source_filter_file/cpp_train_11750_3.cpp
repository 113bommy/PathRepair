#include<stdio.h>
typedef long long int ll;
char a[11];
ll as(int b, ll c, ll d){
	if(a[b]=='\0') return c+d;
	else return as(b+1, c*10+a[b]-'0',d)+as(b+1,a[b]-'0',d+c);
}
int mian(){
	scanf("%s",a);
	printf("%11d\n",as(1,a[0]-'0',0));
	return 0;
}