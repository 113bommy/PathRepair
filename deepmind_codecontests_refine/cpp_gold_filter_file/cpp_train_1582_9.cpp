#include <bits/stdc++.h>
using namespace std;
const int N = 16;
const int MAX_A = 2e3;
int n, k;
int a[N];
void scan() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
}
bitset<N * MAX_A + 1> ok[1 << N];
void build_ok() {
  ok[0][0] = true;
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = N * MAX_A / k * k; i > 0; i -= k) {
      if (ok[mask][i]) {
        ok[mask][i / k] = true;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (~mask >> i & 1) {
        ok[mask ^ 1 << i] |= (ok[mask] << a[i]);
      }
    }
  }
}
void print_ok() {
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < 50; ++i) {
      cout << ok[mask][i];
    }
    cout << '\n';
  }
}
int f(int x) { return x % k || !x ? x : f(x / k); }
int p[N];
void build_p() {
  int cur_mask = (1 << n) - 1;
  int cur_x = 1;
  int cur_p = 0;
  while (cur_mask) {
    bool flag = false;
    while (!flag) {
      if (ok[cur_mask][cur_x]) {
        for (int i = 0; i < n; ++i) {
          if (cur_mask >> i & 1) {
            if (cur_x >= a[i] && ok[cur_mask ^ 1 << i][f(cur_x - a[i])]) {
              cur_mask ^= (1 << i);
              p[i] = cur_p;
              cur_x -= a[i];
              flag = true;
              break;
            }
          }
        }
      }
      if (!flag) {
        cur_x *= k;
        ++cur_p;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    p[i] = cur_p - p[i];
  }
}
void restore_ans() {
  build_p();
  multiset<pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    s.insert({p[i], a[i]});
  }
  while (s.size() > 1) {
    auto x = *s.begin();
    s.erase(s.begin());
    auto y = *s.begin();
    s.erase(s.begin());
    cout << x.second << ' ' << y.second << '\n';
    int sum = x.second + y.second;
    int cnt = 0;
    while (sum % k == 0) {
      sum /= k;
      ++cnt;
    }
    s.insert({x.first + cnt, sum});
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  scan();
  build_ok();
  if (ok[(1 << n) - 1][1]) {
    cout << "YES\n";
    restore_ans();
  } else {
    cout << "NO\n";
  }
  return 0;
}
