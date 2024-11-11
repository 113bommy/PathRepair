#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k=0;
	string a,b;
	cin>>a>>b;
	for(i=0;i<3;i++)
	{
		if(a[i]==b[i])
		k++;
	}
	cout<<k<<"\n";
}