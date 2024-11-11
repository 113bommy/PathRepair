#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 100;
vector<int> vec[100100];
vector<pair<int, int> > Q[100100];
int n, a[100100], m, s[100100], anses[100100], pw[100100], val[100100],
    f[100100], rel[100100];
int get(int l, int r) {
  return l > r ? 0 : (s[l] - 1ll * s[r + 1] * pw[r - l + 1]) % 1000000007;
}
int find(int x) {
  if (x == f[x]) return x;
  int y = f[x];
  f[x] = find(y);
  rel[x] = (rel[x] + rel[y]) % 1000000007;
  return f[x];
}
int main() {
  scanf("%d%d", &n, &m), pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = (pw[i - 1] << 1) % 1000000007;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = n; i >= 1; --i) s[i] = (s[i + 1] * 2ll + a[i]) % 1000000007;
  for (int i = 1; i <= n; ++i) {
    long long nw = 0, ret = 0;
    for (int j = i; j >= 1; --j) {
      nw = nw * 2 + a[j];
      if (nw >= inf) break;
      if (nw <= 0) {
        ret = j - 1, val[i] = nw * 2ll % 1000000007;
        break;
      }
    }
    if (ret) vec[ret].push_back(i);
  }
  for (int i = 1, l, r; i <= m; ++i) {
    scanf("%d%d", &l, &r);
    if (l == r)
      anses[i] = a[l];
    else
      Q[l].push_back(pair<int, int>(r, i));
  }
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < Q[i].size(); ++j) {
      int x = find(Q[i][j].first);
      anses[Q[i][j].second] = (rel[Q[i][j].first] + get(i, x)) % 1000000007;
    }
    for (int j = 0; j < vec[i].size(); ++j) {
      f[vec[i][j]] = i;
      rel[vec[i][j]] = val[vec[i][j]];
    }
  }
  for (int i = 1; i <= m; ++i)
    printf("%d\n", (anses[i] % 1000000007 + 1000000007) % 1000000007);
}
