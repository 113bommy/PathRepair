#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n;cin>>n;
	vector<int>a(n);
	for(auto&& w:a)cin>>w;
	int sm=0;
	for(int i=0;i<n;i++){
		int x=a[i];
		int y=a[x-1];
		if(i==y-1)sm++;
	}
	cout<<sm/2<<endl;
}
