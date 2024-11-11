#include <bits\stdc++.h>
using namespace std;
char a[51][51];
bool b;
int main()
{
	int i,j,m,n,s;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
	  cin>>a[i][j];
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) 
	{
		s=0;
		if (a[i][j]=='#')
		{
			if (a[i+1][j]!='#') s++;
			if (a[i-1][j]!='#') s++;
			if (a[i][j-1]!='#') s++;
			if (a[i][j+1]!='#') s++;
			if (s==4) {
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";
	return 0;
}