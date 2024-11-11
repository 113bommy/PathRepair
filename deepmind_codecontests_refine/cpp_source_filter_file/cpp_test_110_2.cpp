#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const long long infll = (long long)1e18 + 228;
const int inf = 1e9 + 228;
const int mod = 998244353;
const int MOD = 1e9 + 7;
using mem = vector<pair<int, int>>;
int solve(mem a, mem b, mem c) {
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  sort((c).begin(), (c).end());
  int n = a.size();
  int L = 0, R = a.size() + 1;
  while (R - L > 1) {
    bool ok = 0;
    int M = (L + R) / 2;
    int p1 = M - 1;
    int p2 = inf;
    for (int i = 0; i < n; ++i) {
      if (b[i].first > a[p1].first) {
        p2 = i;
        break;
      }
    }
    if (n - p2 >= M) {
      int p3 = inf;
      p2 += M - 1;
      for (int i = 0; i < n; ++i) {
        if (c[i].first > a[p1].first && c[i].first > b[p2].first) {
          p3 = i;
          break;
        }
      }
      ok |= (n - p3 >= M);
    }
    vector<int> yb, yc;
    for (int i = 0; i < n; ++i) {
      if (b[i].first > a[p1].first) {
        yb.emplace_back(b[i].second);
      }
      if (c[i].first > a[p1].first) {
        yc.emplace_back(c[i].second);
      }
    }
    if (yb.size() >= M) {
      nth_element(yb.begin(), yb.begin() + M, yb.end());
      int ct = 0;
      for (auto x : yc) {
        if (x > yb[M - 1]) {
          ++ct;
        }
      }
      ok |= (ct >= M);
    }
    if (ok) {
      L = M;
    } else {
      R = M;
    }
  }
  return L;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  mem a, b, c;
  vector<int> diff;
  for (int i = 0; i < n; ++i) {
    int x, y, col;
    cin >> x >> y >> col;
    if (col == 1) {
      a.emplace_back(x, y);
    } else if (col == 2) {
      b.emplace_back(x, y);
    } else if (col == 3) {
      c.emplace_back(x, y);
    }
  }
  int ans = 0;
  for (int k = 0; k < 4; ++k) {
    ans = max(ans, solve(a, b, c));
    ans = max(ans, solve(a, c, b));
    ans = max(ans, solve(b, a, c));
    ans = max(ans, solve(b, c, a));
    ans = max(ans, solve(c, a, b));
    ans = max(ans, solve(c, b, a));
    for (auto &[x, y] : a) {
      tie(x, y) = make_pair(-y, x);
    }
    for (auto &[x, y] : b) {
      tie(x, y) = make_pair(-y, x);
    }
    for (auto &[x, y] : c) {
      tie(x, y) = make_pair(-y, x);
    }
  }
  cout << 3 * ans << '\n';
}
