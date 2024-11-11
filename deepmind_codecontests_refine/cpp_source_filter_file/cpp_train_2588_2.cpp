#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	int num, a, b, i, k = 0, sum = 0;
	long long H, W, ss;
	cin >> H >> W >> num;
	ss = (H - 2) * (W - 2);
	vector<pair<int, int>> list(9 * num);
	vector<int> ans(10, 0);
	map<pair<int, int>, int> mp;
	pair<int, int> p;
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		for (int j = -1; j < 2; j++) {
			for (int l = -1; l < 2; l++) {
				p = make_pair(a + j, b + l);
				if (mp[p] == 0)
					list[k++] = p;
				mp[p]++;
			}
		}
	}
	for (i = 0; i < 9 * num; i++) {
		if (list[i].first > 1 && list[i].first < H && list[i].second > 1 && list[i].second < W) {
			ans[mp[list[i]]]++;
			sum++;
		}
	}
	cout << ss - sum << "\n";
	for (i = 1; i < 10; i++)
		cout << ans[i] << "\n";
	return 0;
}