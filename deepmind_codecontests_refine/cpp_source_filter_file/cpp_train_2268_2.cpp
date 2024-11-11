#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b>>c;
	if((a==b&&b!=c)||(a==c%%b!=c)||(b==c&&a!=b)) cout<<"Yes";
	else cout<<"No";
	return 0;
}