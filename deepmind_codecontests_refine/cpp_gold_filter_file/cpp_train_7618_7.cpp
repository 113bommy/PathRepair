#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;
long long t, n, m, sum;
long long num[510][510], vis[510][510];
void solve(void) {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> num[i][j];
      if (num[i][j] > 0) vis[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (num[i][j] > 0) {
        if (i < n && num[i + 1][j] > 0 && num[i][j] >= num[i + 1][j]) {
          cout << -1 << endl;
          return;
        }
        if (j < m && num[i][j + 1] > 0 && num[i][j] >= num[i][j + 1]) {
          cout << -1 << endl;
          return;
        }
      }
    }
  }
  for (int i = 1; i <= n - 1; ++i) {
    for (int j = 1; j <= m - 1; ++j) {
      if (num[i][j] == 0) {
        int k = j, cnt = 1;
        while (num[i][++k] == 0) cnt++;
        int temp = num[i][k];
        if (num[i][k] - num[i][j - 1] <= cnt) {
          cout << -1 << endl;
          return;
        }
        for (int p = k - 1; p >= j; --p) num[i][p] = --temp;
      }
    }
  }
  for (int i = n; i >= 2; --i) {
    for (int j = m; j >= 2; --j) {
      if (num[i][j] <= num[i - 1][j]) {
        if (vis[i - 1][j] == 1) {
          cout << -1 << endl;
          return;
        }
        num[i - 1][j] = num[i][j] - 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) sum += num[i][j];
  cout << sum << endl;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
