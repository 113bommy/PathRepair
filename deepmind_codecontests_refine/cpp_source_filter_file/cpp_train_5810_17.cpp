#inlcude<bits/stdc++.h>
using namespace std;
long long a,b,k;
int main()
{
	cin>>a>>b;
	if((a+b)%2==0)
	cout<<(a+b)/2;
	else
	cout<<"IMPOSSIBLE";
	return 0; 
}