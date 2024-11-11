#include<bits/stdc++.h>
using namespace std;
int n,a;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		if((a&1)==0)if(a%3&&a%5)
		{
			puts("DENIED");
			return 0;
		}
	}
	puts("APPROVED");
	return 0;
}
