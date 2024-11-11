#include <bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int left = 0;
	int right = s.size()-1;
	ll ans = 0;
	while(left!=right){
		if(s[left]==s[right]){
			left++;
			right--;
		}else if(s[left]=='x'){
			left++;
			ans++;
		}else if(s[right]=='x'){
			right--;
			ans++;
		}else{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}