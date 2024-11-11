#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b,s;
	cin>>a>>b;
	int n,m;
	cin>>n>>m;cin>>s;
	if(s==a) cout<<n-1<<' '<<m<<endl;
	else cout<<n<<' '<<m-1<<endl;
}