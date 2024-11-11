#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  const int maxn = 200000 + 9;
  vector<vector<int>> div(maxn);
  for (int i = 1; i < maxn; ++i) {
    for (int j = i; j < maxn; j += i) {
      div[j].push_back(i);
    }
  }
  set<int> S;
  vector<int> c(maxn);
  int L = m + 1, R = m + 1;
  for (int i = 1; i <= n; ++i) {
    long long y1l = (l + i - 1) / i, y1r = min(r / i, m);
    if (y1l > y1r) {
      cout << -1 << "\n";
      continue;
    }
    while (L > y1l) {
      --L;
      for (int j : div[L]) {
        c[j]++;
        if (c[j] == 1) S.insert(j);
      }
    }
    while (R > y1r + 1) {
      --R;
      assert(R >= 0);
      for (int j : div[R]) {
        c[j]--;
        if (c[j] == 0) S.erase(j);
      }
    }
    bool fd = 0;
    for (int a : div[i]) {
      auto it = S.upper_bound(a);
      if (it != S.end() && 1ll * i / a * (*it) <= n) {
        int x1 = i, y1 = y1r / (*it) * (*it), x2 = i / a * (*it);
        int y2 = 1ll * x1 * y1 / x2;
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
        fd = 1;
        break;
      }
    }
    if (!fd) {
      cout << -1 << '\n';
    }
  }
  return 0;
}
