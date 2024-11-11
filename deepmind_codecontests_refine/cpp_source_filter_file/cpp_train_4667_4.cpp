#include <bits/stdc++.h>
using namespace std;

int main() {
	int H,W;cin>>H>>W;
	vector<string> a(H);
	for (int i = 0; i < H; i++) cin >> a[i];

	vector<bool> row(H, false);
	vector<bool> col(W, false);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		if (row[i]) {
			for (int j = 0; j < w; j++) {
				if (col[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}
