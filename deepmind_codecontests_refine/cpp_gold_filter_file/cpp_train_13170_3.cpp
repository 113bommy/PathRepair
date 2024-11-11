#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int N = 2102;
int dpf[N][N], dpr[N][N];
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  for (int i = n; i >= 1; --i)
    for (int j = m; j >= 1; --j)
      if (s[i - 1] == t[j - 1]) dpf[i][j] = dpf[i + 1][j + 1] + 1;
  reverse(s.begin(), s.end());
  for (int i = n; i >= 1; --i)
    for (int j = m; j >= 1; --j)
      if (s[i - 1] == t[j - 1]) dpr[i][j] = dpr[i + 1][j + 1] + 1;
  bool flag = true;
  vector<pair<int, int>> v;
  for (int i = 1; i <= m; ++i) {
    int len1 = 0, len2 = 0, p1 = 0, p2 = 0;
    for (int j = 1; j <= n; ++j) {
      if (dpf[j][i] > len1) {
        len1 = dpf[j][i];
        p1 = j;
      }
    }
    for (int j = 1; j <= n; ++j) {
      if (dpr[j][i] > len2) {
        len2 = dpr[j][i];
        p2 = j;
      }
    }
    if (len1 || len2) {
      if (len1 >= len2) {
        int l = p1, r = p1 + len1 - 1;
        i += len1 - 1;
        v.push_back(make_pair(l, r));
      } else {
        int l = n - p2 + 1, r = n - (p2 + len2) + 2;
        i += len2 - 1;
        v.push_back(make_pair(l, r));
      }
    } else {
      flag = false;
      break;
    }
  }
  if (flag == false)
    cout << "-1\n";
  else {
    cout << v.size() << "\n";
    for (auto i : v) cout << i.first << " " << i.second << "\n";
  }
}
