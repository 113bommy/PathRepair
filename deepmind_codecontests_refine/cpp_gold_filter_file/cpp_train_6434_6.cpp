#include<stdio.h>
int main()
{
	int n,m,a,b,l,r;
	while(~scanf("%d %d", &n, &m))
	{
		a=0;b=200000;
		while(m--)
		{
			scanf("%d %d", &l, &r);
			if(l>a)
				a=l;
			if(r<b)
				b=r;
		}
		if(b-a<0) printf("0\n");
		else printf("%d\n", b-a+1);
	}
	return 0;
}