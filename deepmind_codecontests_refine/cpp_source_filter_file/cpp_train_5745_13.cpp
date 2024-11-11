#include <bits/stdc++.h>
using namespace std;
struct A {
  int n;
  string s;
  void solve() {
    cin >> n >> s;
    for (int i = 0; i < (1 << n); i++) {
      int tmp = i;
      bool good = 1;
      for (char c : s) {
        if (c == 'L') {
          bool fl = 0;
          for (int v = 0; v < 10; v++) {
            if (tmp & (1 << v)) continue;
            fl = 1;
            tmp ^= (1 << v);
            break;
          }
          if (!fl) {
            good = 0;
            break;
          }
        } else if (c == 'R') {
          bool fl = 0;
          for (int v = 9; v >= 0; v--) {
            if (tmp & (1 << v)) continue;
            fl = 1;
            tmp ^= (1 << v);
            break;
          }
          if (!fl) {
            good = 0;
            break;
          }
        } else {
          if (tmp & (1 << (c - '0'))) {
            tmp ^= (1 << (c - '0'));
          } else {
            good = 0;
            break;
          }
        }
      }
      if (good) {
        for (int i = 0; i < 10; i++) {
          cout << bool(tmp & (1 << i));
        }
        return;
      }
    }
  }
};
struct B {
  int n, m, k;
  void solve() {
    cin >> n >> m >> k;
    vector<int> h(n);
    for (int &first : h) cin >> first;
    for (int i = 1; i < n; i++) {
      m += (h[i - 1] - max(1, h[i] - k));
      if (m < 0) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
  }
};
void run() {
  int t;
  cin >> t;
  while (t--) {
    B first;
    first.solve();
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  run();
}
