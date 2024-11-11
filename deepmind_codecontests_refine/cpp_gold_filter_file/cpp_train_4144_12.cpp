#include<bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
	int ans;
	cin>>a>>b;
	ans=ceil(1.0*(b-1)/(a-1));
	cout<<ans;
	return 0;
}