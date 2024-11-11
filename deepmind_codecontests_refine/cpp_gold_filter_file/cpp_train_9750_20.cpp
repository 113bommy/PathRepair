#include <bits/stdc++.h>
using namespace std;
long double PI = acosl(-1);
struct base {
  long double a, b;
  base(long double a = 0, long double b = 0) : a(a), b(b) {}
  const base operator+(const base &c) const { return base(a + c.a, b + c.b); }
  const base operator-(const base &c) const { return base(a - c.a, b - c.b); }
  const base operator*(const base &c) const {
    return base(a * c.a - b * c.b, a * c.b + b * c.a);
  }
};
void fft(vector<base> &p, bool inv = 0) {
  int n = p.size(), i = 0;
  for (int j = 1; j < n - 1; ++j) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1)
      ;
    if (j < i) swap(p[i], p[j]);
  }
  for (int l = 1, m; (m = l << 1) <= n; l <<= 1) {
    long double ang = 2 * PI / m;
    base wn = base(cos(ang), (inv ? 1. : -1.) * sin(ang)), w;
    for (int i = 0, j, k; i < n; i += m) {
      for (w = base(1, 0), j = i, k = i + l; j < k; ++j, w = w * wn) {
        base t = w * p[j + l];
        p[j + l] = p[j] - t;
        p[j] = p[j] + t;
      }
    }
  }
  if (inv)
    for (int i = 0; i < n; ++i) p[i].a /= n, p[i].b /= n;
}
vector<bool> multiply(vector<bool> &a, vector<bool> &b) {
  int n = a.size(), m = b.size(), t = n + m - 1, sz = 1;
  while (sz < t) sz <<= 1;
  vector<base> x(sz), y(sz), z(sz);
  for (int i = 0; i < sz; ++i) {
    x[i] = i < a.size() ? base(a[i], 0) : base(0, 0);
    y[i] = i < b.size() ? base(b[i], 0) : base(0, 0);
  }
  fft(x), fft(y);
  for (int i = 0; i < sz; ++i) z[i] = x[i] * y[i];
  fft(z, 1);
  vector<bool> ret(sz);
  for (int i = 0; i < sz; ++i) {
    long long ds = z[i].a + 0.5;
    if (ds == 0)
      ret[i] = 0;
    else
      ret[i] = 1;
  }
  while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
  return ret;
}
int vis[200], casio, cnt;
vector<int> vc[200];
void dfs(int v) {
  vis[v] = casio;
  cnt++;
  for (int i = 0; i < vc[v].size(); i++) {
    int w = vc[v][i];
    if (vis[w] == casio) continue;
    dfs(w);
  }
}
string str, str2;
vector<bool> tp[3], cp[3], ret[103][103];
int main() {
  int i, j, k, l, m, n;
  cin >> str >> str2;
  reverse(str2.begin(), str2.end());
  for (int i = 97; i <= 102; i++) {
    for (int j = i + 1; j <= 102; j++) {
      for (int k = 0; k < 2; k++) {
        tp[k].clear();
        cp[k].clear();
      }
      for (int k = 0; str[k]; k++) {
        if (str[k] == i)
          tp[0].push_back(1);
        else
          tp[0].push_back(0);
        if (str[k] == j)
          tp[1].push_back(1);
        else
          tp[1].push_back(0);
      }
      for (int k = 0; str2[k]; k++) {
        if (str2[k] == j)
          cp[0].push_back(1);
        else
          cp[0].push_back(0);
        if (str2[k] == i)
          cp[1].push_back(1);
        else
          cp[1].push_back(0);
      }
      ret[i][j] = multiply(tp[0], cp[0]);
      vector<bool> r = multiply(tp[1], cp[1]);
      if (r.size() > ret[i][j].size()) ret[i][j].resize(r.size());
      for (int k = 0; k < r.size(); k++) {
        if (r[k]) ret[i][j][k] = r[k];
      }
    }
  }
  int f = str2.size() - 1;
  for (int i = 0; str[i]; i++) {
    int d = f + i;
    if ((i + str2.size() - 1) >= str.size()) break;
    for (int k = 97; k <= 102; k++) vc[k].clear();
    for (int l = 97; l <= 102; l++) {
      for (int k = l + 1; k <= 102; k++) {
        if (ret[l][k].size() <= d) continue;
        if (ret[l][k][d]) {
          vc[l].push_back(k);
          vc[k].push_back(l);
        }
      }
    }
    casio++;
    int ans = 0;
    for (int k = 97; k <= 102; k++) {
      if (vis[k] == casio) continue;
      cnt = 0;
      dfs(k);
      ans += cnt - 1;
    }
    printf("%d ", ans);
  }
}
