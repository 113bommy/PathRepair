#include <bits/stdc++.h>
using namespace std;
char a[10001],b[10001];
int main()
{
	gets_s(a);
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		b[l-i-1]=a[i];
		if(a[i]=='b') a[i]='d';
		else if(a[i]=='d') a[i]='b';
		else if(a[i]=='p') a[i]='q';
		else if(a[i]=='q') a[i]='p';
	}
	for(int i=0;i<l;i++)
		if(a[i]!=b[i]) puts("No"),exit(0);
	puts("Yes");
	return 0;
}