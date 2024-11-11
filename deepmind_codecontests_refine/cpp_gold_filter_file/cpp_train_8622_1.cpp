#include<iostream>
#include<vector>
using namespace std;

vector<bool>flag(100005);
vector<int>cnt(100005);

int main() {
	for (int i = 2; i <= 100000; i++)if (!flag[i])for (int j = i + i; j <= 100000; j += i)flag[j] = true;
	for (int i = 3; i <= 100000; i += 2)if (!flag[i] && !flag[(i + 1) / 2])cnt[i]++;
	for (int i = 3; i <= 100000; i++)cnt[i] += cnt[i - 1];
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		cout << cnt[r] - cnt[l-1] << endl;
	}

	return 0;
}