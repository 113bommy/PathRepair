#include <bits/stdc++.h>
using namespace std;
long long mo(long long a) { return a % (long long)(1e9 + 7); }
long long po(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
long long n, m;
vector<long long> a, res;
vector<vector<long long>> g, mat;
vector<vector<pair<long long, long long>>> que;
struct dsuTree {
  vector<long long> si;
  vector<long long> dp;
  vector<vector<long long>> sub;
  void init(long long n) {
    si.assign(n, 0);
    sub.assign(n, {});
    dp.assign(n, 1);
    dfs_size(0);
    dfs(0);
  }
  void dfs_size(int par, int anc = -1) {
    si[par] = 1;
    for (auto e : g[par]) {
      if (e != anc) {
        dp[e] = dp[par] + 1;
        dfs_size(e, par);
        si[par] += si[e];
      }
    }
  }
  void dfs(int par, int anc = -1, bool keep = true) {
    int maxi = -1, bigchild = -1;
    for (int e : g[par]) {
      if (e != anc && maxi < si[e]) {
        maxi = si[e];
        bigchild = e;
      }
    }
    for (int e : g[par]) {
      if (e != anc && e != bigchild) {
        dfs(e, par, 0);
      }
    }
    if (bigchild != -1) {
      dfs(bigchild, par, 1);
      swap(sub[par], sub[bigchild]);
    }
    sub[par].push_back(par);
    mat[dp[par]][a[par]]++;
    for (int e : g[par]) {
      if (e != anc && e != bigchild) {
        for (int x : sub[e]) {
          mat[dp[e]][a[e]]++;
          sub[par].push_back(x);
        }
      }
    }
    for (pair<long long, long long> e : que[par]) {
      long long h = e.first, in = e.second, cnt = 0;
      for (long long i = 0; i < 26; i++) {
        if (mat[h][i] & 1) cnt++;
      }
      if (cnt < 2)
        res[in] = 1;
      else
        res[in] = 0;
    }
    if (!keep) {
      for (int e : sub[par]) {
        mat[dp[e]][a[e]]--;
      }
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  g.assign(n, {});
  a.assign(n, 0);
  for (long long i = 1; i < n; i++) {
    long long x;
    cin >> x;
    x--;
    g[x].push_back(i);
    g[i].push_back(x);
  }
  for (long long i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    a[i] = ch - 'a';
  }
  que.assign(n, {});
  for (long long i = 0; i < m; i++) {
    long long x, h;
    cin >> x >> h;
    x--;
    que[x].push_back({h, i});
  }
  res.assign(m, 0);
  mat.assign(n + 1, vector<long long>(26, 0));
  dsuTree ds;
  ds.init(n);
  for (long long i = 0; i < m; i++) {
    if (res[i])
      cout << "Yes";
    else
      cout << "No";
    cout << "\n";
  }
  return 0;
}
