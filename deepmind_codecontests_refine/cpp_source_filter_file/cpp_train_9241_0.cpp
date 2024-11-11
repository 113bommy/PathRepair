#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;cin>>k;
	string s;cin>>s;
	int p=s.size();
	if(p<=k)
	cout<<s;
	else{
		for(ll i=0;i<k;i++)cout<<s[i];
		cout<<"...";
		
	}
}