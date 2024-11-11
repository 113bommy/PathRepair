#include <bits/stdc++.h>
using namespace std;

#define int long long

int cnt[2019];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	cnt[0] = 1;
	int p = 1, now = 0, ans = 0;
	for(int i=s.size()-1; i>=0; --i){
		now = (now + (s[i] - '0') * p) % 2019;
		ans += cnt[now];
		++cnt[now];
		p = ((p << 3) + (p << 1)) %2019;
	}
	cout << ans << "\n";

	return 0;
}
