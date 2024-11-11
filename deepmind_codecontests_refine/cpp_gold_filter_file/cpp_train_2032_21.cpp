#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int n, m;
long long a[maxn], b[maxn], sa, sb;
map<long long, pair<int, int> > ma;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sa += a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    sb += b[i];
  }
  if (sa == sb) {
    cout << "0\n0\n";
    return;
  }
  long long cur = abs(sa - sb);
  int cnt = 0;
  pair<int, int> a1, a2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (abs(sa - sb + 2 * (b[j] - a[i])) < cur) {
        cur = abs(sa - sb + 2 * (b[j] - a[i]));
        cnt = 1;
        a1 = {i, j};
      }
    }
  }
  if (cur == 0) {
    cout << "0\n1\n" << a1.first << " " << a1.second << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ma[(a[i] + a[j]) * 2] = {i, j};
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      long long t = (sa - sb + 2 * (b[i] + b[j]));
      auto it = ma.lower_bound(t);
      if (it != ma.end()) {
        if (abs(t - it->first) < cur) {
          cur = abs(t - it->first);
          cnt = 2;
          a1 = it->second;
          a2 = {i, j};
        }
      }
      if (it != ma.begin()) {
        it--;
        if (abs(t - it->first) < cur) {
          cur = abs(t - it->first);
          cnt = 2;
          a1 = it->second;
          a2 = {i, j};
        }
      }
    }
  }
  cout << cur << endl;
  cout << cnt << endl;
  if (cnt == 1) {
    cout << a1.first << " " << a1.second << endl;
  } else if (cnt == 2) {
    cout << a1.first << " " << a2.first << endl;
    cout << a1.second << " " << a2.second << endl;
  }
}
int main() {
  solve();
  return 0;
}
