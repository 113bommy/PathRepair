#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,k,x,y;
	cin>>n>>k>>x>>y;
	cout<<min(k,n)*x+max(0*1LL,n-k)*y;
}