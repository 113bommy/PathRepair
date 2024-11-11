#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long l = 1, r = 1 << 30;
  set<int> s;
  int ret = 0;
  long long b = 0;
  int sign = 1;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (~x & 1) {
      int mid = x / 2;
      if (s.find((mid - b) * sign) != s.end() || (l <= mid && mid <= r)) {
        ret += 2;
        s.clear();
        l = r = mid;
        b = 0, sign = 1;
      } else {
        ret += 1;
        swap(l, r);
        l = max(x - l, 1ll);
        r = min(x - r, x - 1ll);
        while (!s.empty()) {
          auto it = s.begin();
          long long u = (*it) * sign + b;
          if (u < 1 || u > x - 1) {
            s.erase(it);
          } else {
            break;
          }
        }
        while (!s.empty()) {
          auto it = s.end();
          it--;
          long long u = (*it) * sign + b;
          if (u < 1 || u > x - 1) {
            s.erase(it);
          } else {
            break;
          }
        }
        if (l <= r) {
          s.insert((mid - b) * sign);
        } else {
          l = r = mid;
        }
        sign *= -1;
        b = x - b;
      }
    } else {
      swap(l, r);
      l = max(x - l, 1ll);
      r = min(x - r, x - 1);
      while (!s.empty()) {
        auto it = s.begin();
        long long u = (*it) * sign + b;
        if (u < 1 || u > x - 1) {
          s.erase(it);
        } else {
          break;
        }
      }
      while (!s.empty()) {
        auto it = s.end();
        it--;
        long long u = (*it) * sign + b;
        if (u < 1 || u > x - 1) {
          s.erase(it);
        } else {
          break;
        }
      }
      sign *= -1;
      b = x - b;
      if (l <= r || !s.empty()) {
        if (l > r) {
          auto it = s.begin();
          l = r = (*it) * sign + b;
          s.erase(it);
        }
        ret++;
      } else {
        l = 1;
        r = x - 1;
        sign = 1;
        b = 0;
      }
    }
    if (l > r) {
      abort();
    }
  }
  cout << n * 2 + 1 - ret << endl;
}
int main() {
  int T = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
