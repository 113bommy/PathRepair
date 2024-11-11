#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6, md = 1004535809;
mt19937 mt(time(0));
int base, _[N], n, m, hx[27];
pair<int, int> DT[27];
int H[27][N], e[30];
char s[N], t[N];
inline int get(int* h, int l, int r) {
  return (h[r] - (long long)h[l - 1] * _[r - l + 1] % md + md) % md;
}
int main() {
  scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
  if (n < m) return puts("0"), 0;
  base = mt() % 233333 + 666666;
  for (int i = *_ = 1; i <= n; ++i) _[i] = (long long)_[i - 1] * base % md;
  for (int i = 0; i < 27; ++i) {
    int& F = hx[i];
    for (int j = 1; j <= m; ++j)
      F = ((long long)F * base + 1 + (i + 'a' == t[j])) % md;
  }
  for (int i = 0; i < 26; ++i) DT[i] = make_pair(hx[i], i);
  sort(DT, DT + 26);
  for (int i = 0; i < 26; ++i)
    for (int j = 1; j <= n; ++j)
      H[i][j] = ((long long)H[i][j - 1] * base + 1 + (i + 'a' == s[j])) % md;
  vector<int> ans;
  for (int i = 1; i + m - 1 <= n; ++i) {
    pair<int, int> h[26];
    for (int j = 0; j < 26; ++j) h[j] = make_pair(get(H[j], i, i + m - 1), j);
    sort(h, h + 26);
    memset(e, -1, sizeof e);
    bool ok = 1;
    for (int j = 0; j < 26; ++j)
      if (h[j].first != DT[j].first)
        ok = 0;
      else if (DT[j].first != hx[26]) {
        int x = DT[j].second, y = h[j].second;
        if (e[x] == -1 && e[y] == -1)
          e[x] = y, e[y] = x;
        else if (e[x] != y || e[y] != x)
          ok = 0;
      }
    if (ok) ans.push_back(i);
  }
  printf("%d\n", ans.size());
  for (int i : ans) printf("%d ", i);
  return 0;
}
