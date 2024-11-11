#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	vector< vector<string> > S(h, vector<string>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> S[i][j];
			if (S[i][j] == "snuke") {
				cout << (char)('A' + j) << i + 1 << endl;
			}
		}
	}
	return 0;
}