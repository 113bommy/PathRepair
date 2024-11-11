#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string,int> mp;
	for(int a=0;a<n;a++){
		string str;
		cin >> str;
		mp[str]++;
	}
	int m;
	cin >> m;
	for(int a=0;a<m;a++){
		string str;
		cin >> str;
		mp[str]--;
	}
	int  ans=0;
	for(pair<string,int> pa:mp){
		ans=max(pair.second,ans);
	}
	cout << ans << endl;
	return 0;
}