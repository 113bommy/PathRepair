#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,b=0,r=0;
	char c;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c",&c);
		if(c=='R')
			r++;
		else
			b++;
	}
	if(r>b)
		printf("Yes");
	else 
		printf("No");
	return 0;
}