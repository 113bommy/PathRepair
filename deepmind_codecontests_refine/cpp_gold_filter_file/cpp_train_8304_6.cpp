#include<cstdio>

int main()
{
	int h,n,s=0;
	scanf("%d%d",&h,&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		s+=x;
	}
	printf("%s\n",h<=s?"Yes":"No");
	return 0;
}