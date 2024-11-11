#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = 606;
vector<int> g[maxn];
int cnt[maxn], in[maxn], out[maxn];
int M[maxn][maxn], order[maxn], O = 0;
bool used[maxn];
void dfs(int v) {
  used[v] = true;
  for (__typeof((g[v]).begin()) it = (g[v]).begin(); it != (g[v]).end(); it++)
    if (!used[*it]) {
      dfs(*it);
    }
  order[O++] = v;
}
int binpow(int a, int mod) {
  int b = mod - 2;
  int res = 1;
  while (b > 0) {
    if (b & 1) res = res * 1LL * a % mod;
    a = a * 1LL * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].push_back(b);
    ++in[b];
    ++out[a];
  }
  vector<int> lf, rg;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) {
      lf.push_back(i);
    }
    if (out[i] == 0) {
      rg.push_back(i);
    }
  }
  for (int i = 0; i < n; i++)
    if (!used[i]) {
      dfs(i);
    }
  reverse(order, order + O);
  int k = (int)(lf).size();
  for (int i = 0; i < k; i++) {
    memset(cnt, 0, sizeof(cnt));
    cnt[lf[i]] = 1;
    for (int j = 0; j < O - 1; j++) {
      int v = order[j];
      for (__typeof((g[v]).begin()) it = (g[v]).begin(); it != (g[v]).end();
           it++) {
        cnt[*it] += cnt[v];
        cnt[*it] %= p;
      }
    }
    for (int j = 0; j < k; j++) {
      M[i][j] = cnt[rg[j]];
    }
  }
  int res = 1;
  int tmp = 1;
  for (int i = 0; i < k; i++) {
    int w = -1;
    for (int j = i; j < k; j++) {
      if (M[j][i] != 0) {
        w = j;
        break;
      }
    }
    if (w == -1) {
      res = 0;
      break;
    }
    if (w != i) res *= -1;
    for (int j = i; j < k; j++) {
      swap(M[i][j], M[w][j]);
    }
    for (int j = i + 1; j < k; j++)
      if (M[j][i]) {
        tmp = tmp * 1LL * M[i][i] % p;
        int t = M[j][i];
        for (int r = i; r < k; r++) {
          M[j][r] = ((M[j][r] * 1LL * M[i][i] - M[i][r] * 1LL * t) % p + p) % p;
        }
      }
  }
  tmp = binpow(tmp, p);
  for (int i = 0; i < k; i++) {
    tmp = tmp * 1LL * M[i][i] % p;
  }
  tmp = tmp * res;
  if (tmp < 0) tmp += p;
  cout << tmp << endl;
  return 0;
}
