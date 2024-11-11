#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int M = 1e6;
const int mod = 1e9 + 7;
int n, m, len, sz[N + 10];
string s[N + 10], ans;
vector<int> v[2 * M + 10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> m;
    sz[i] = (int)s[i].size();
    while (m--) {
      int x;
      cin >> x;
      v[x - 1].push_back(i);
      len = max(sz[i] + x - 1, len);
    }
  }
  int idx = -1, maxr = 0, pos = 0;
  for (int i = 0; i < len; i++) {
    for (int j = (int)v[i].size() - 1; j >= 0; j--) {
      int r = i + sz[v[i][j]] - 1;
      if (r > maxr) {
        idx = v[i][j];
        maxr = r;
        pos = 0;
      }
    }
    if (idx == -1)
      ans += 'a';
    else
      ans += s[idx][pos++];
    if (pos >= sz[idx]) idx = -1, maxr = 0;
  }
  cout << ans;
  return 0;
}
