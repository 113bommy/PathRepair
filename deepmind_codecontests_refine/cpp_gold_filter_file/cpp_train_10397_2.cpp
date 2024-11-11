#include <bits/stdc++.h>
using namespace std;
bool t[15];
bool ok(int n)
{
	while(n>0)
	{
		if(t[n%10])
			return false;
		n/=10;
	}
	return true;
}
int main()
{
	int n,k,a;
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a;
		t[a]=true;
	}
	while(!ok(n))
		n++;
	cout<<n;

	return 0;
}