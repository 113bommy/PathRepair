#include <bits/stdc++.h>
using namespace std;
void z_function(string &s, vector<int> &z) {
  int n = s.length(), l = -1, r = -1;
  z.clear();
  z.resize(n, 0);
  z[0] = n;
  for (int i = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (z[i] + i < n && s[z[i]] == s[z[i] + i]) z[i]++;
    if (z[i] + i - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}
int n, m, q, l, r;
string s, t;
vector<int> z, pr;
int main() {
  cin >> n >> m >> q;
  cin >> s >> t;
  n = s.length();
  m = t.length();
  s = t + '#' + s;
  z_function(s, z);
  pr.resize(n, 0);
  if (z[m + 1] == m) pr[0] = 1;
  for (int i = 1; i < n; i++) {
    pr[i] = pr[i - 1];
    if (z[m + 1 + i] == m) pr[i]++;
  }
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    l--;
    r--;
    if (r - m + 1 < 0) {
      cout << 0 << endl;
      continue;
    }
    if (l == 0)
      cout << pr[r - m + 1];
    else
      cout << pr[r - m + 1] - pr[l - 1];
    cout << endl;
  }
  return 0;
}
