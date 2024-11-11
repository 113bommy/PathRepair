#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	vector<string> s(h);
	rep(i, h)cin >> s[i];
	int ans = 0;
	rep(is, 1 << h)rep(js, 1 << w) {
		int cnt = 0;
		rep(i, h)rep(j, w){
			if (is >> i & 1)continue;
			if (js >> j & 1)continue;
			if (s[i][j] == '#')cnt++;
		}
		if (cnt == k)ans++;
	}
	cout << ans << endl;
	return 0;
}