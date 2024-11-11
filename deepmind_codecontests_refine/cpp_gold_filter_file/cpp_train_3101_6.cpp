#include<bits/stdc++.h>
using namespace std;
long double a,b,c;
int main(){
	cin>>a>>b>>c;
	if(sqrt(c)-sqrt(b)-sqrt(a)>=1e-14)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}