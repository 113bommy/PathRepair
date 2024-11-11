#include <bits/stdc++.h>
using namespace std;

int n;
vector < int > ans;

signed main () { 
    cin >> n;
	if(n==3){
		ans.push_back(2);
		ans.push_back(3);
		ans.push_back(25);
	}
	for(int i=1;ans.size()<=n-2 and i<30000;i++){
		int q=i/12,r=i%12;
		if(r<=1 or r>=6 or 12%r!=0)
			continue;
		ans.push_back(12*q+r);
		ans.push_back(12*q+12-r);
	}
	for(int i=1;ans.size()<=n-2 and 24*i<=30000;i++){
		ans.push_back(24*i-18);
		ans.push_back(24*i-6);
	}
	for(int i=1;ans.size()<n and 12*i<=30000;i++)
		ans.push_back(12*i);
	assert(ans.size()==n);
	for(int i=0;i<n;i++)
		cout << ans[i] << " ";
	return 0;
}
