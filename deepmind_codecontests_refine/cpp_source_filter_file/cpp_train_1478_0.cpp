#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int a[N][N], b[N][N], x[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  for (int _ = 0; _ < 2; ++_)
    for (int i = 0; i < n; ++i) {
      cin >> s;
      for (int j = 0; j < n; ++j) a[i][j] ^= s[j] == '1', b[i][j] = a[i][j];
    }
  cin >> s;
  int k = -1;
  for (int i = 0; i < n; ++i)
    if (s[i] == '1') x[i] = 1, k = i;
  if (k == -1) {
    bool flag = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) flag |= a[i][j];
    if (flag) return cout << -1, 0;
  }
  vector<int> vr, vc;
  for (int j = 0; j < n; ++j)
    if (a[k][j]) {
      vc.push_back(j);
      for (int i = 0; i < n; ++i) a[i][j] ^= x[i];
    }
  bool ans = 1;
  for (int i = 0; i < n; ++i) {
    bool f1 = 1, f2 = 1;
    for (int j = 0; j < n; ++j) f1 &= a[i][j] == 0, f2 &= a[i][j] == x[j];
    if (not(f1 or f2)) ans = 0;
    if (f2) vr.push_back(i);
  }
  if (ans) {
    cout << vc.size() + vr.size() << '\n';
    for (int it : vc) cout << "col " << it + 1 << '\n';
    for (int it : vr) cout << "row " << it + 1 << '\n';
    return 0;
  }
  for (int j = 0; j < n; ++j) b[k][j] ^= 1;
  vr.clear(), vc.clear();
  for (int j = 0; j < n; ++j)
    if (a[k][j]) {
      vc.push_back(j);
      for (int i = 0; i < n; ++i) a[i][j] ^= 1;
    }
  ans = 1;
  for (int i = 0; i < n; ++i) {
    bool f1 = 1, f2 = 1;
    for (int j = 0; j < n; ++j) f1 &= a[i][j] == 0, f2 &= a[i][j] == x[j];
    if (not(f1 or f2)) ans = 0;
    if (f2) vr.push_back(i);
  }
  if (ans) {
    cout << vc.size() + vr.size() << '\n';
    for (int it : vc) cout << "col " << it << '\n';
    for (int it : vr) cout << "row " << it << '\n';
    return 0;
  }
  cout << -1;
  return 0;
}
