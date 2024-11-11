#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
struct Matrix {
  int sz;
  long long g[maxn][maxn];
  Matrix(int x) {
    sz = x;
    memset(g, -1, sizeof g);
  }
  void init() {
    memset(g, -1, sizeof g);
    for (int i = 0; i < sz; i++) g[i][i] = 0;
  }
  Matrix operator*(const Matrix& o) const {
    Matrix ret(sz);
    ret.init();
    for (int k = 0; k < sz; k++)
      for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++)
          if (~g[i][k] && ~o.g[k][j])
            ret.g[i][j] = max(ret.g[i][j], g[i][k] + o.g[k][j]);
    return ret;
  }
};
struct AC {
  int sz;
  int ch[maxn][26], fail[maxn], val[maxn];
  void init() {
    sz = 1;
    val[0] = 0;
    memset(ch[0], 0, sizeof ch[0]);
  }
  void insert(char* s, int v) {
    int u = 0, n = strlen(s);
    for (int i = 0; i < n; i++) {
      int id = s[i] - 'a';
      if (!ch[u][id]) {
        val[sz] = 0;
        memset(ch[sz], 0, sizeof ch[sz]);
        ch[u][id] = sz++;
      }
      u = ch[u][id];
    }
    val[u] += v;
  }
  void build() {
    queue<int> q;
    fail[0] = 0;
    for (int i = 0; i < 26; i++) {
      int u = ch[0][i];
      if (!u) continue;
      fail[u] = 0;
      q.push(u);
    }
    while (!q.empty()) {
      int r = q.front();
      q.pop();
      for (int i = 0; i < 26; i++) {
        int u = ch[r][i];
        if (!u) {
          ch[r][i] = ch[fail[r]][i];
        } else {
          fail[u] = ch[fail[r]][i];
          val[u] += val[fail[u]];
          q.push(u);
        }
      }
    }
  }
  long long slove(long long n) {
    Matrix a(sz);
    for (int i = 0; i < sz; i++)
      for (int j = 0; j < 26; j++) {
        int u = ch[i][j];
        if (!u) continue;
        a.g[u][i] = max(a.g[u][i], (long long)val[u]);
      }
    Matrix res(sz);
    res.init();
    while (n) {
      if (n & 1) res = res * a;
      a = a * a;
      n = n / 2;
    }
    long long ret = 0;
    for (int i = 0; i < sz; i++) ret = max(ret, res.g[i][0]);
    return ret;
  }
} ac;
int v[maxn];
int main() {
  int n;
  long long l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) scanf("%d", v + i);
  char s[maxn];
  ac.init();
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    ac.insert(s, v[i]);
  }
  ac.build();
  cout << ac.slove(l) << endl;
  return 0;
}
