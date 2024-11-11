#include <bits/stdc++.h>
using namespace std;

int main()
{
	string n;
	cin>>n;
	
	long long sum=0;
	
	for( auto x : n)
	sum= sum + x-'0';
	
	if( sum % 9 ==0)
	cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}