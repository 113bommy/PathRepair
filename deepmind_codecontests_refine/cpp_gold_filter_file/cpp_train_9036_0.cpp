#include<bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	long long ans = 0, count = 0;
	for(int i = 0; i	 < s.size(); ++i){
		if(s[i] == 'B') count++;
		else ans += count;
	}
	cout << ans << endl;
}
