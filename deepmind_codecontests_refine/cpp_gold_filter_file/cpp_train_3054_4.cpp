#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int MAXN = 607;
int powMod(int x, int y, int p) {
  long long ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = ret * x % p;
    x = (long long)x * x % p;
  }
  return ret;
}
int detModPrime(int a[MAXN][MAXN], int n, int p) {
  bool neg = false;
  for (int i = 0; i < n; ++i) {
    int j = i;
    for (; j < n && a[j][i] == 0; ++j)
      ;
    if (j == n) return 0;
    if (j != i) {
      neg = !neg;
      for (int k = 0; k < n; ++k) swap(a[i][k], a[j][k]);
    }
    for (j = i + 1; j < n; ++j) {
      long long co = (long long)(p - a[j][i]) * powMod(a[i][i], p - 2, p) % p;
      for (int k = i; k < n; ++k) a[j][k] = (a[j][k] + co * a[i][k]) % p;
    }
  }
  long long ret = neg ? (p - 1) : 1;
  for (int i = 0; i < n; ++i) ret = ret * a[i][i] % p;
  return ret;
}
vector<int> e[MAXN * 2];
int n, m, p;
int in[MAXN * 2], out[MAXN * 2], f[MAXN * 2];
int inn[MAXN * 2], mat[MAXN][MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> p;
  memset(in, 0, sizeof(in)), memset(out, 0, sizeof(out));
  vector<int> source, sink;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ++out[a];
    ++in[b];
    e[a].push_back(b);
  }
  int col = 0, row = 0, same = 0;
  for (int i = 0; i < n; i++) {
    if (out[i] && !in[i]) {
      ++col;
      source.push_back(i);
    }
    if (in[i] && !out[i]) {
      ++row;
      sink.push_back(i);
    }
    if (!in[i] && !out[i]) same += col + row;
  }
  for (int i = 0; i < source.size(); i++) {
    for (int j = 0; j < n; j++) f[j] = 0, inn[j] = in[j];
    f[source[i]] = 1;
    queue<int> Q;
    for (int j = 0; j < source.size(); j++) Q.push(source[j]);
    while (Q.size()) {
      int now = Q.front();
      Q.pop();
      for (typeof(e[now].begin()) it = e[now].begin(); it != e[now].end();
           it++) {
        f[*it] = (f[*it] + f[now]) % p;
        --inn[*it];
        if (!inn[*it]) Q.push(*it);
      }
    }
    for (int j = 0; j < source.size(); j++) mat[i][j] = f[sink[j]];
  }
  int ans = detModPrime(mat, sink.size(), p);
  if (same & 1) ans = p - ans;
  cout << ans % p << endl;
  return 0;
}
