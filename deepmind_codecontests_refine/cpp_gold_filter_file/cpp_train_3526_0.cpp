#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double n,tmp,sum=0;
	while(scanf("%lf",&n)!=EOF)
	{
		sum=0;
		tmp = n;
		for(int i=1;i<=10;i++)
		{
			if(i==1)
			{
			}
			else if(i%2==0)
			{
				tmp *=2;
			}
			else
			{
				tmp /=3;
			}
			sum += tmp;
		}
		printf("%.8f\n",sum);
	}
	return 0;
}