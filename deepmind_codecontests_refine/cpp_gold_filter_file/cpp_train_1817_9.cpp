#include <bits/stdc++.h>
using namespace std;
int n, m, k, typ[510], id[510];
int P;
vector<int> s[510];
long double mp[510][510];
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
struct MAT {
  long double a[510][510];
} mat;
struct VEC {
  long double a[510];
} vec;
MAT operator*(const MAT &a, const MAT &b) {
  MAT ret;
  for (int i = 1; i <= P; ++i)
    for (int j = 1; j <= P; ++j) ret.a[i][j] = 0;
  for (int i = 1; i <= P; ++i)
    for (int t = 1; t <= P; ++t) {
      if (a.a[i][t] < 5e-8) continue;
      for (int j = 1; j <= P; ++j) {
        ret.a[i][j] += a.a[i][t] * b.a[t][j];
      }
    }
  return ret;
}
VEC operator*(const MAT &a, const VEC &b) {
  VEC ret;
  for (int i = 1; i <= P; ++i) {
    ret.a[i] = 0;
    for (int t = 1; t <= P; ++t) ret.a[i] += a.a[i][t] * b.a[t];
  }
  return ret;
}
void write() {
  puts("-------");
  for (int i = 1; i <= P; ++i)
    for (int j = 1; j <= P; ++j) printf("%.10Lf%c", mat.a[i][j], " \n"[j == P]);
}
int main() {
  read(n), read(m), read(k);
  for (int i = 1; i <= n; ++i) read(typ[i]);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u), read(v);
    s[u].push_back(v);
    s[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (typ[i] == 1) {
      mat.a[i][i] = 1;
      continue;
    }
    for (unsigned j = 0, si = s[i].size(); j < si; ++j) {
      int to = s[i][j];
      mat.a[to][i] += 1.0 / si;
    }
  }
  P = n;
  for (int p = 1; p <= 15; ++p) mat = mat * mat;
  int tot = 0;
  for (int p = 1; p <= n; ++p) {
    if (!typ[p]) continue;
    id[p] = ++tot;
    for (int i = 1; i <= P; ++i) vec.a[i] = 0;
    for (unsigned j = 0, si = s[p].size(); j < si; ++j) {
      int to = s[p][j];
      vec.a[to] += 1.0 / si;
    }
    vec = mat * vec;
    for (int i = 1; i <= n; ++i) mp[p][i] = vec.a[i];
  }
  memset(vec.a, 0, sizeof(vec.a));
  vec.a[1] = 1;
  vec = mat * vec;
  static VEC tmp = vec;
  memset(vec.a, 0, sizeof(vec.a));
  for (int i = 1; i <= n; ++i)
    if (typ[i]) vec.a[id[i]] = tmp.a[i];
  memset(mat.a, 0, sizeof(mat.a));
  P = tot;
  for (int i = 1; i <= n; ++i)
    if (typ[i]) {
      for (int j = 1; j <= n; ++j)
        if (typ[j]) {
          mat.a[id[j]][id[i]] = mp[i][j];
        }
    }
  MAT ret;
  memset(ret.a, 0, sizeof(ret.a));
  for (int i = 1; i <= P; ++i) ret.a[i][i] = 1;
  k -= 2;
  while (k) {
    if (k & 1) ret = ret * mat;
    mat = mat * mat;
    k >>= 1;
  }
  vec = ret * vec;
  printf("%.10Lf\n", vec.a[id[n]]);
  return 0;
}
