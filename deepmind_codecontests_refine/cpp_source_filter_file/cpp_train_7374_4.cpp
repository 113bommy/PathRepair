#include<bits/stdc++.h>
using namespace std;
long long z;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		z+=a-b+1;
	}
	cout<<z<<endl;
	return 0;
}