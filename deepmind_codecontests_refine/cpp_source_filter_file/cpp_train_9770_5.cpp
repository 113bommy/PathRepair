#inhclude<stdio.h>
int main(void)
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a+b>=10)	printf("error\n");
	else	printf("%d",a+b);
	return 0;
}
