#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(ios::badbit | ios::failbit);
  int n, m, qn;
  cin >> n >> m >> qn;
  vector<vector<int>> state(n, vector<int>(m));
  vector<set<int>> notfree(n + m + 10);
  int delta = m + 5;
  for (auto i = -2; i <= n + 2; ++i) {
    for (auto j = -2; j <= m + 2; ++j) {
      notfree[i - j + delta].insert(i);
    }
  }
  42;
  long long res = 0;
  auto calc = [&](int i, int j) -> long long {
    42;
    42;
    42;
    42;
    42;
    42;
    long long res = -1;
    auto temp = notfree[i - j + delta].lower_bound(i);
    int x = *temp - i;
    int rx = i - *prev(temp);
    42;
    {
      auto it = notfree[i - j - 1 + delta].lower_bound(i);
      42;
      int y = *it - i;
      int p = x <= y ? 2 * x : 2 * x - 1;
      int ry = i - 1 - *prev(it);
      int q = rx <= ry ? 2 * rx : 2 * rx - 1;
      42;
      res += 1LL * p * q;
    }
    {
      auto it = notfree[i - j + 1 + delta].lower_bound(i + 1);
      42;
      int y = *it - i - 1;
      int p = x <= y ? 2 * x : 2 * x - 1;
      int ry = i - *prev(it);
      int q = rx <= ry ? 2 * rx : 2 * rx - 1;
      42;
      res += 1LL * p * q;
    }
    42;
    return res;
  };
  auto flip = [&](int i, int j) -> void {
    if (state[i][j]) {
      res -= calc(i, j);
      state[i][j] ^= 1;
      notfree[i - j + delta].insert(i);
    } else {
      state[i][j] ^= 1;
      notfree[i - j + delta].erase(i);
      res += calc(i, j);
    }
  };
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < m; ++j) {
      flip(i, j);
    }
  }
  42;
  for (auto qi = 0; qi < qn; ++qi) {
    int i, j;
    cin >> i >> j, --i, --j;
    flip(i, j);
    cout << res << "\n";
  }
  return 0;
}
