#include"bits/stdc++.h"
using namespace std;
int main()
{
	int n,t,x,y;
	bool f=true;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&t,&x,&y);
		if(t%(x+y)!=0&&(t-x-y)%2!=0||t<(x+y))
			f=false;
	}
	if(f) 
		printf("Yes");
	else
		printf("No");
	return 0;
}
 