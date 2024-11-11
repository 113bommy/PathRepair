#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[505][505],b[505],Ans,Mn,sum;
char nc()
{
	char c=getchar();
	while(c!='#'&&c!='.') c=getchar();
	return c;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)b[i]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		a[i][j]=(nc()=='#'),b[j]&=a[i][j],sum+=a[i][j];
	if (!sum) return puts("-1"),0;
	for (int i=1;i<=n;i++)
		if (!b[i]) Ans++;
	Mn=100000000;
	for (int i=1;i<=n;i++)
	{
		int t=0,now=0;
		for (int j=1;j<=n;j++)
			if (a[j][i]) {t=j;break;}
		if (t==0) now++;
		for (int j=1;j<=n;j++)
			if (!a[i][j]) now++;
		Mn=min(Mn,now);
	}
	if (Mn==100000000)
		puts("-1");
	else printf("%d\n",Mn+Ans);
	
}