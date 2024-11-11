#include <bits/stdc++.h>
using namespace std;

int n,y;
int main()
{
	cin>>n>>y;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n-i;j++)
		{
			int p=n-i-j;
			if(10000*i+5000*j+1000*k==y){
				cout<<i<<' '<<j<<' '<<k;
				return 0;
		}
	cout<<"-1 -1 -1";
	return 0;
}