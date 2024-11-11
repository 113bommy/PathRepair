#include<iostream>
#include<vector>
#define int long long
using namespace std;
signed main(){
	int n,a,b;
	cin>>n>>a>>b;
	cout<<min(a,b)<<" "<<max(a+b-n,0);
}