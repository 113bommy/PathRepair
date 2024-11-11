#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = 2 * acos(0.0);
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  vector<int> b = a;
  sort(b.begin(), b.end());
  bool ok = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      ok = 0;
      break;
    }
  }
  if (ok) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < n; j += 2) {
        if (j + 1 < n && a[j + 1] < a[j]) {
          swap(a[j], a[j + 1]);
        }
      }
    } else {
      for (int j = 1; j < n; j += 2) {
        if (j + 1 < n && a[j + 1] < a[j]) {
          swap(a[j], a[j + 1]);
        }
      }
    }
    bool okk = 1;
    for (int j = 0; j < n; j++) {
      if (a[i] != b[i]) {
        okk = 0;
        break;
      }
    }
    if (okk) {
      cout << i + 1 << '\n';
      return;
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
