#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,x;
	cin>>a>>b;
	x=max({a*b,a+b,a-b});
	cout<<x<<endl;
	return 0;
}