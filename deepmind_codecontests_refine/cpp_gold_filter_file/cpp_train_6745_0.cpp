#include<stdio.h>
#include<string.h>
int main()
{
	int l,i,a=0;
	char s[105];
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<(l+1)/2;i++)
	{
		if(s[i]!=s[l-1-i])a++;
	}
	printf("%d\n",a);
}