#include <bits/stdc++.h>
using namespace std;
int chh;
const int N = 205, CH = 26;
const long long INF = 1e18;
typedef long long mat[N][N];
int n;
long long m;
int a[N];
char s[N];
int E;
mat ret, tmp, g;
void mul(mat a, mat b) {
  for (int i = 0; i < (E); i++)
    for (int j = 0; j < (E); j++) tmp[i][j] = -INF;
  for (int i = 0; i < (E); i++)
    for (int j = 0; j < (E); j++)
      for (int k = 0; k < (E); k++) {
        tmp[i][j] = max(tmp[i][j], a[i][k] + b[k][j]);
      }
  for (int i = 0; i < (E); i++)
    for (int j = 0; j < (E); j++) a[i][j] = tmp[i][j];
}
void power(mat a, long long y) {
  for (int i = 0; i < (E); i++)
    for (int j = 0; j < (E); j++) {
      ret[i][j] = -INF;
      g[i][j] = a[i][j];
    }
  for (int i = 0; i < (E); i++) ret[i][i] = 0;
  while (y) {
    if (y & 1) mul(ret, g);
    mul(g, g);
    y >>= 1LL;
  }
}
struct Aho_Corasick {
  int e;
  int chd[N][CH];
  int wv[N], fail[N], q[N];
  void init() {
    e = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    wv[0] = 0;
  }
  void add(char s[], int val) {
    int i, id, p = 0;
    for (i = 0; s[i]; i++) {
      id = s[i] - 'a';
      if (chd[p][id] == -1) {
        memset(chd[e], -1, sizeof(chd[e]));
        wv[e] = 0;
        chd[p][id] = e++;
      }
      p = chd[p][id];
    }
    wv[p] += val;
  }
  void build() {
    int i, p, v, l, r;
    fail[0] = l = r = 0;
    for (i = 0; i < CH; i++) {
      v = chd[0][i];
      if (v != -1) {
        fail[v] = 0;
        q[r++] = v;
      } else
        chd[0][i] = 0;
    }
    while (l != r) {
      p = q[l++];
      for (i = 0; i < CH; i++) {
        v = chd[p][i];
        if (v != -1) {
          fail[v] = chd[fail[p]][i];
          q[r++] = v;
          wv[v] += wv[fail[v]];
        } else
          chd[p][i] = chd[fail[p]][i];
      }
    }
  }
  void solve() {
    int v;
    long long ans;
    mat a;
    E = e;
    for (int i = 0; i < (E); i++)
      for (int j = 0; j < (E); j++) a[i][j] = -INF;
    for (int i = 0; i < (e); i++)
      for (int j = 0; j < (CH); j++) {
        v = chd[i][j];
        a[i][v] = wv[v];
      }
    power(a, m);
    ans = -INF;
    for (int j = 0; j < (E); j++) ans = max(ans, ret[0][j]);
    printf("%I64d\n", ans);
  }
} AC;
int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < (n); i++) scanf("%d", &a[i]);
    AC.init();
    for (int i = 0; i < (n); i++) {
      scanf("%s", s);
      AC.add(s, a[i]);
    }
    AC.build();
    AC.solve();
  }
  return 0;
}
