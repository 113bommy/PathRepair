#include<bits/stdc++.h>
using namespace std;
long long z,a,b,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		z+=b-a+1;
	}
	cout<<z<<endl;
	return 0;
}