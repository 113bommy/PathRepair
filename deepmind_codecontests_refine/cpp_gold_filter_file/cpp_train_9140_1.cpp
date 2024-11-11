#include <bits/stdc++.h>
using namespace std;

int n;
double a[3005];
double ans;
double f[3005][3005];

int main()
{
	cin>>n;
	for(int i=1;i<=n;cin>>a[i++]);
	f[0][0] = 1.0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			f[i][j] = f[i-1][j-1]*a[i]+f[i-1][j]*(1-a[i]);
	for(int i=n/2+1;i<=n;i++)
		ans += f[n][i];
	printf("%.11lf\n",ans);
	
	return 0;
}