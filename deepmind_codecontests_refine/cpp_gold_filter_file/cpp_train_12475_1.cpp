#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int main()
{
	cin>>z>>x>>y;
	if((y-x-1)%2==1) cout<<"Alice";
	else cout<<"Borys";
	return 0;
}