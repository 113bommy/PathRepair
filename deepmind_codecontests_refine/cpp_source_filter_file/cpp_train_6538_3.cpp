#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h);
	set<pair<int, int>> p;
	for (int i = 0; i < h; i++) {
		a[i].resize(w);
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#')
				p.insert({ i, j });
		}
	}
	int d[][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
	int ans = 0;
	while (!p.empty()) {
		set<pair<int, int>> s;
		for (auto const& x : p) {
			for (auto const y : d) {
				int i = x.first + y[0], y = x.second + y[1];
				if (i >= 0 && i < h && j >= 0 && j < w && a[i][j] == '.')
					s.insert({ i, j});
			}
		}
		if (!s.empty()) {
			ans++;
			for (auto const& x : s)
				a[x.first][x.second] = '#';
		}
		p = move(s);
	}
	cout << ans << '\n';

	return 0;
}
