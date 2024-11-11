#include"bits/stdc++.h"
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	string c=b;
	reverse(c.begin(),c.end());
	if(a==c)
		cout<<"YES";
	else
		cout<<"NO";
}