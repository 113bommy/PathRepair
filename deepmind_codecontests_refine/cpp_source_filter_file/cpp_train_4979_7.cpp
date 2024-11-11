#include<bits/stdc++>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a*b==15)
	{
		printf("*");
	}
	else if(a+b==15)
	{
		printf("+");
	}
	else
	{
		printf("x")； 
	}
	return 0;
} 