#include <bits/stdc++.h>
using namespace std;
#define int long long
int n = 0, l = 0, pos[300500], tim[300500], ans = 0;
bool del[300500], fir[300500], sec[300500];
signed main() {
	ios::sync_with_stdio(false);
	cin >> n >> l; ans = n + 1;
	for(int i = 1; i <= n; i++) {
		cin >> pos[i];
	} for(int i = 1; i <= n; i++) {
		cin >> tim[i];
		ans += (tim[i] / (l * 2)) , tim[i] %= (l * 2);
		if(tim[i] == 0) {
			ans--, del[i] = true;
			continue;
		}
		fir[i] = (2 * (l - pos[i]) >= tim[i]);
		sec[i] = (2 * pos[i] >= tim[i]);
		del[i] = not (fir[i] or sec[i]);
	}
	ans -= fir[n];
	int sum = 0, top = 0, pos = n;
	for(int i = 1; i < n; i++) {
		if(del[i]) continue;
		if(not fir[i]) {
			pos = i;
			break;
		}
		if(sec[i]) {
			top++;
		} else {
			if(top) {
				top--, ans--;
			}
		}
	}
	sum += top, top = 0;
	for(int i = n - 1; i >= pos; i--) {
		if(del[i]) continue;
		if(not sec[i]) break;
		if(fir[i]) {
			top++;
		} else {
			if(top) {
				top--, ans--;
			}
		}
	}
	ans -= (sum + top) / 2;
	cout << 2 * l * ans << endl;
	return 0;
}