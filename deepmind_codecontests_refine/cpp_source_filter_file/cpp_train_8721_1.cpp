#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a[n],s=0;
	for(int i = 0 ; i < n; i ++)
	{
		cin >> a[i];
		s+= a[i];
	}
	int k = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i]*4*m>=s)
          k++;
	}
	i
	cout << (k>=m?"Yes":"No") <<"\n";
	
}