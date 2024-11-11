#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
ostream &operator<<(ostream &i, pair<T1, T2> j) {
  return i << j.first << ' ' << j.second;
}
template <typename T>
ostream &operator<<(ostream &i, vector<T> j) {
  i << '{' << j.size() << ':';
  for (T ii : j) i << ' ' << ii;
  return i << '}';
}
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7, INF = 0x3f3f3f3f3f3f3f3f;
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    k = 2 * k + 1;
    string s[n], t[n];
    for (string &i : s) cin >> i;
    for (string &i : t) i = string(m, '.');
    for (int i = n - 1; ~i; --i)
      for (int j = 0; j < m; ++j)
        if (s[i][j] == '*') {
          vector<pair<int, int> > v(1, make_pair(i, j));
          for (int x = 1; true; ++x)
            if (i - x >= 0 && j - x >= 0 && j + x < m &&
                s[i - x][j - x] == '*' && s[i - x][j + x] == '*')
              v.emplace_back(i - x, j + x), v.emplace_back(i - x, j - x);
            else
              break;
          if ((int)v.size() >= k)
            for (pair<int, int> x : v) t[x.first][x.second] = '*';
        }
    string ans("YES\n");
    for (int i = 0; i < n; ++i)
      if (s[i] != t[i]) ans = "NO\n";
    cout << ans;
  }
}
