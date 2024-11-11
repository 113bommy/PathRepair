#include <bits/stdc++.h>
using namespace std;
int func(string &t, string &p) {
  int c = 0;
  for (int i = 0; i < t.length() && c < p.length(); i++) {
    if (t[i] == p[c]) c++;
  }
  if (c == p.length()) return 1;
  return 0;
}
int main() {
  string t;
  string p;
  cin >> t >> p;
  int n = t.length();
  vector<int> v(n);
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> v[i];
  int mi = 0, ma = n - 1;
  string k;
  while (mi <= ma) {
    k = t;
    int mid = (mi + ma) / 2;
    for (int i = 0; i <= mid; i++) k[v[i] - 1] = '0';
    if (func(k, p)) {
      ans = mid;
      mi = mid + 1;
    } else {
      ma = mid - 1;
    }
  }
  cout << ans + 1;
  return 0;
}
