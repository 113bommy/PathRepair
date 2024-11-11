#include <bits/stdc++.h>
using namespace std;
int n, t;
long long c[262144], g[262144][18], p[19][262144], r[385];
char e[18][18];
map<vector<int>, int> m;
inline void orFMT(long long *a, int n) {
  for (int i = 1; i < (1 << n); i <<= 1)
    for (int j = 0; j < (1 << n); j += (i << 1))
      for (int k = 0; k < i; ++k) a[i + j + k] = a[i + j + k] + a[j + k];
}
inline void andFMT(long long *a, int n) {
  for (int i = 1; i < (1 << n); i <<= 1)
    for (int j = 0; j < (1 << n); j += (i << 1))
      for (int k = 0; k < i; ++k) a[j + k] = a[j + k] - a[i + j + k];
}
void split(int x, int s, int l) {
  static vector<int> v;
  if (s == n) {
    int u;
    m[v] = t;
    for (int i = 1; i < (1 << n); ++i) {
      u = 1;
      for (int j = 0; j < l; ++j) u *= p[v[j]][i];
      r[t] += (n - c[i]) & 1 ? -u : u;
    }
    ++t;
    return;
  }
  for (int i = x; i <= n - s; ++i) {
    v.push_back(i);
    split(i, s + i, l + 1);
    v.pop_back();
  }
}
int main() {
  static vector<int> v;
  int u;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", e[i]);
    g[1 << i][i] = 1;
    for (int j = 0; j < n; ++j) e[i][j] ^= 48;
  }
  for (int i = 0; i < (1 << n); ++i) {
    c[i] = c[i >> 1] + (i & 1);
    for (int j = 0; j < n; ++j)
      if (i & (1 << j)) {
        for (int k = 0; k < n; ++k)
          if ((i & (1 << k)) && e[j][k]) g[i][j] += g[i ^ (1 << j)][k];
        p[c[i]][i] += g[i][j];
      }
  }
  for (int i = 1; i <= n; ++i) orFMT(p[i], n);
  split(1, 0, 0);
  --n;
  for (int i = 0; i < (1 << n); ++i) {
    v.clear();
    u = -1;
    for (int j = 0; j < n; ++j)
      if (!(i & (1 << j))) {
        v.push_back(j - u);
        u = j;
      }
    v.push_back(n - u);
    sort(v.begin(), v.end());
    c[i] = r[m[v]];
  }
  andFMT(c, n);
  for (int i = 0; i < (1 << n); ++i) printf("%lld ", c[i]);
  return 0;
}
