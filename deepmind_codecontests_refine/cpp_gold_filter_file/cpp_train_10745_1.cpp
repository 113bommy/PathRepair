#include <bits/stdc++.h>
using namespace std;
const int q = 1000000007;
int n, m, p, r, t[100010], c[100010], d[100010], w[100010], u[100010],
    v[100010], f[100010][400], g[400][400];
bool o[100010];
vector<int> a[100010], b[100010], x[400], y[100010];
map<vector<int>, int> h;
inline void pre(int n, vector<int> x) {
  if (n == -1) {
    if (!h[x]) {
      h[x] = ++p;
      ::x[p] = x;
    }
    return;
  }
  vector<int> y = x;
  pre(n - 1, x);
  int i, j;
  for (i = (1 << n); i < (1 << n + 1); i++) {
    x = y;
    x.push_back(i);
    for (j = 0; j < x.size() - 1; j++)
      if (x[j] & (1 << n)) x[j] ^= i;
    pre(n - 1, x);
  }
}
inline void dfs(int i, int j) {
  int k;
  t[i] = r;
  for (k = 0; k < a[i].size(); k++)
    if (a[i][k] != 1 && a[i][k] != j)
      if (!t[a[i][k]]) {
        w[a[i][k]] = w[i] ^ b[i][k];
        dfs(a[i][k], i);
      } else if (i < a[i][k])
        y[r].push_back(w[i] ^ w[a[i][k]] ^ b[i][k]);
}
inline int get(int i, int j) {
  int k;
  for (k = 0; k < a[i].size(); k++)
    if (a[i][k] == j) return b[i][k];
}
inline bool cmp(int i, int j) { return i > j; }
inline int get(vector<int> x) {
  if (x.size() > 5) return 0;
  int i, j;
  for (i = 0; i < x.size(); i++) {
    sort(x.begin(), x.end(), cmp);
    for (j = 0; j < x.size(); j++)
      if (i != j)
        if (x[i] == x[j])
          return 0;
        else if ((x[i] ^ x[j]) < x[j])
          x[j] ^= x[i];
  }
  return h[x];
}
int main() {
  int i, j, k, l;
  pre(4, vector<int>());
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &j, &k, &l);
    a[j].push_back(k);
    b[j].push_back(l);
    a[k].push_back(j);
    b[k].push_back(l);
  }
  for (i = 0; i < a[1].size(); i++)
    if (!t[a[1][i]]) {
      r++;
      c[r] = a[1][i];
      d[r] = b[1][i];
      dfs(a[1][i], 1);
      u[r] = get(y[r]);
    } else {
      k = t[a[1][i]];
      y[k].push_back(d[k] ^ b[1][i] ^ get(a[1][i], c[k]));
      v[k] = get(y[k]);
      o[k] = 1;
    }
  for (i = 1; i <= p; i++)
    for (j = 1; j <= p; j++) {
      vector<int> a = x[i];
      for (auto k : x[j]) a.push_back(k);
      g[i][j] = get(a);
    }
  f[1][1] = 1;
  for (i = 1; i <= r; i++)
    for (j = 1; j <= p; j++)
      if (f[i][j]) {
        f[i + 1][j] = (f[i + 1][j] + f[i][j]) % q;
        k = g[j][u[i]];
        if (!o[i])
          f[i + 1][k] = (f[i + 1][k] + f[i][j]) % q;
        else {
          f[i + 1][k] = (f[i + 1][k] + 2ll * f[i][j]) % q;
          k = g[j][v[i]];
          f[i + 1][k] = (f[i + 1][k] + f[i][j]) % q;
        }
      }
  for (i = 1, k = 0; i <= p; i++) k = (k + f[r + 1][i]) % q;
  printf("%d\n", k);
  return 0;
}
