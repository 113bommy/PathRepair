#include <bits/stdc++.h>
static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;
template <class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(k), y(k);
  vector<vector<int>> r(n);
  vector<vector<int>> c(m);
  for (int i = 0; i < k; ++i) {
    scanf("%d %d", &x[i], &y[i]);
    r[x[i] - 1].emplace_back(y[i]);
    c[y[i] - 1].emplace_back(x[i]);
  }
  for (int i = 0; i < n; ++i) {
    sort(r[i].begin(), r[i].end());
  }
  for (int j = 0; j < m; ++j) {
    sort(c[j].begin(), c[j].end());
  }
  ll remain = (ll)n * m - k - 1;
  int x1 = 0, x2 = n + 1, y1 = 0, y2 = m + 1, p = 1, q = 1, turn = 0;
  while (true) {
    if (turn == 0) {
      int to = y2;
      if (!r[p - 1].empty()) {
        auto val = lower_bound(r[p - 1].begin(), r[p - 1].end(), q);
        if (val != r[p - 1].end()) {
          to = min(to, *val);
        }
      }
      if (to - 1 == q) break;
      x1 = max(x1, p);
      remain -= (to - 1 - q);
      q = to - 1;
    } else if (turn == 1) {
      int to = x2;
      if (!c[q - 1].empty()) {
        auto val = lower_bound(c[q - 1].begin(), c[q - 1].end(), p);
        if (val != c[q - 1].end()) {
          to = min(to, *val);
        }
      }
      if (to - 1 == p) break;
      y2 = min(y2, q);
      remain -= (to - 1 - p);
      p = to - 1;
    } else if (turn == 2) {
      int to = y1;
      if (!r[p - 1].empty()) {
        auto val = upper_bound(r[p - 1].begin(), r[p - 1].end(), q);
        if (val != r[p - 1].begin()) {
          to = max(to, *(val - 1));
        }
      }
      if (to + 1 == q) break;
      x1 = min(x1, p);
      remain -= (q - to - 1);
      q = to + 1;
    } else if (turn == 3) {
      int to = x1;
      if (!c[q - 1].empty()) {
        auto val = upper_bound(c[q - 1].begin(), c[q - 1].end(), p);
        if (val != c[q - 1].begin()) {
          to = max(to, *(val - 1));
        }
      }
      if (to + 1 == p) break;
      y1 = max(y1, q);
      remain -= (p - to - 1);
      p = to + 1;
    }
    turn++;
    if (turn == 4) turn = 0;
  }
  if (remain == 0) {
    puts("Yes");
    return 0;
  }
  remain = (ll)n * m - k - 1;
  x1 = 0, x2 = n + 1, y1 = 0, y2 = m + 1, p = 1, q = 1, turn = 1;
  while (true) {
    if (turn == 0) {
      int to = y2;
      if (!r[p - 1].empty()) {
        auto val = lower_bound(r[p - 1].begin(), r[p - 1].end(), q);
        if (val != r[p - 1].end()) {
          to = min(to, *val);
        }
      }
      if (to - 1 == q) break;
      x1 = max(x1, p);
      remain -= (to - 1 - q);
      q = to - 1;
    } else if (turn == 1) {
      int to = x2;
      if (!c[q - 1].empty()) {
        auto val = lower_bound(c[q - 1].begin(), c[q - 1].end(), p);
        if (val != c[q - 1].end()) {
          to = min(to, *val);
        }
      }
      if (to - 1 == p) break;
      y2 = min(y2, q);
      remain -= (to - 1 - p);
      p = to - 1;
    } else if (turn == 2) {
      int to = y1;
      if (!r[p - 1].empty()) {
        auto val = upper_bound(r[p - 1].begin(), r[p - 1].end(), q);
        if (val != r[p - 1].begin()) {
          to = max(to, *(val - 1));
        }
      }
      if (to + 1 == q) break;
      x1 = min(x1, p);
      remain -= (q - to - 1);
      q = to + 1;
    } else if (turn == 3) {
      int to = x1;
      if (!c[q - 1].empty()) {
        auto val = upper_bound(c[q - 1].begin(), c[q - 1].end(), p);
        if (val != c[q - 1].begin()) {
          to = max(to, *(val - 1));
        }
      }
      if (to + 1 == p) break;
      y1 = max(y1, q);
      remain -= (p - to - 1);
      p = to + 1;
    }
    turn++;
    if (turn == 4) turn = 0;
  }
  if (remain == 0) {
    puts("Yes");
    return 0;
  }
  puts("No");
  return 0;
}
