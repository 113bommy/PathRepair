//半数列挙で答えが8以下かを判定する.
//順列は, 16進数で表現する.
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int n;
int a[10], decA, basePermDec;
vector<int> perms[2][5];

void dfs(int type, int depth, int maxDepth, int nowP) {
	perms[type][depth].push_back(nowP);
	if (depth == maxDepth) return;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int nextP = nowP & ((1LL << (4 * (j + 1))) - 1);
			nextP = (nextP >> (4 * i)) << (4 * i);
			nextP = nowP - nextP;
			for (int k = 0; k <= j - i; k++) {
				int idl = i + k;
				int idr = j - k;
				nextP += ((nowP >> (4 * idr)) & 15) << (4 * idl);
			}
			dfs(type, depth + 1, maxDepth, nextP);
		}
	}
}

bool isMatch(int depth1, int depth2) {
	vector<int> &a = perms[0][depth1];
	vector<int> &b = perms[1][depth2];
	int i, j;
	
	if (a.size() == 0 || b.size() == 0) return false;
	
	j = 0;
	for (i = 0; i < a.size(); i++) {
		for (; j < b.size(); j++) {
			if (a[i] <= b[j]) {
				break;
			}
		}
		if (j < b.size() && a[i] == b[j]) return true;
	}
	return false;
}

signed main() {
	int i, j;
	
	cin >> n;
	for (i = 0; i < n; i++) { cin >> a[i]; a[i]--; }
	for (i = 0; i < n; i++) decA += a[i] << (4 * i);
	for (i = 0; i < n; i++) basePermDec += i << (4 * i);
	dfs(0, 0, 4, basePermDec);
	dfs(1, 0, 4, decA);

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 5; j++) {
			sort(perms[i][j].begin(), perms[i][j].end());
			perms[i][j].erase(unique(perms[i][j].begin(), perms[i][j].end()), perms[i][j].end());
		}
	}
		
	int ans = 9;
	for (i = 0; i <= 4; i++) {
		for (j = 0; j <= 4; j++) {
			if (isMatch(i, j)) {
				ans = min(ans, i + j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
