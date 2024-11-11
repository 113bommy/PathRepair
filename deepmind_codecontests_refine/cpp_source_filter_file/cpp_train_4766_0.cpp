#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q,w;
	cin>>q>>w;
	if(w%2==1) cout<<"No";
	else if(q*4<w) cout<<"No";
	else if(q*2>w) cout"No";
	else cout<<"Yes";
}