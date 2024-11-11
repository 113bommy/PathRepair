#include<bits/stdc++.h>
using namespace std;
int main()
{
	char n[20];
	int flag=1;
	scanf("%s",n);
	for(i=1;i<strlen(n);i++)
	{
		if(n[i]!=9)
			flag=0;
	}
	printf("%d",(strlen(n)-1)*9+(flag?n[0]-'0':n[0]-'1'));
	return 0;
} 