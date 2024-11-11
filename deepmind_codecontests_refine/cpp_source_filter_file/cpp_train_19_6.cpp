#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
vector<int> a[300001];
int p[1000001];
int f[1000001];
const int Max = 6e5;
const int T = 3e5;
int root(int u) {
  if (u == p[u]) return u;
  return p[u] = root(p[u]);
}
void Merge(int u, int v) {
  u = root(u);
  v = root(v);
  int ru = root(u);
  int rv = root(v);
  p[rv] = ru;
  f[ru] += f[rv];
}
int main() {
  cin >> n >> k >> s;
  s = '.' + s;
  for (int i = 1; i <= Max; i++) {
    p[i] = i;
    f[i] = -1;
  }
  for (int i = 1; i <= k; i++) {
    int len;
    cin >> len;
    while (len--) {
      int x;
      cin >> x;
      a[x].push_back(i);
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      if (a[i].size() == 1) {
        int u = a[i][0];
        if (f[root(u + T)] == -1) {
          f[root(u + T)] = 1;
          res++;
        }
        if (f[root(u)] != -1) {
          res -= min(f[root(u)], f[root(u + T)]);
          f[root(u)] = 1e9;
          res += min(f[root(u)], f[root(u + T)]);
        }
        f[root(u)] = 1e9;
      } else if (a[i].size() == 2) {
        int u = a[i][0];
        int v = a[i][1];
        if (f[root(u)] == -1) f[root(u)] = 0;
        if (f[root(u + T)] == -1) f[root(u + T)] = 1;
        if (f[root(v)] == -1) f[root(v)] = 0;
        if (f[root(v + T)] == -1) f[root(v + T)] = 1;
        if (root(u) != root(v + T)) {
          res -= min(f[root(u)], f[root(u + T)]);
          res -= min(f[root(v)], f[root(v + T)]);
          Merge(u, v + T);
          Merge(u + T, v);
          res += min(f[root(u)], f[root(u + T)]);
        }
      }
    } else {
      if (a[i].size() == 1) {
        int u = a[i][0];
        if (f[root(u + T)] != -1) {
          res -= min(f[root(u)], f[root(u + T)]);
          f[root(u + T)] = 1e9;
          res += min(f[root(u)], f[root(u + T)]);
        }
        if (f[root(u)] == -1) f[root(u)] = 0;
        f[root(u + T)] = 1e9;
      } else if (a[i].size() == 2) {
        int u = a[i][0];
        int v = a[i][1];
        if (f[root(u)] == -1) f[root(u)] = 0;
        if (f[root(u + T)] == -1) f[root(u + T)] = 1;
        if (f[root(v)] == -1) f[root(v)] = 0;
        if (f[root(v + T)] == -1) f[root(v + T)] = 1;
        if (root(u) != root(v)) {
          res -= min(f[root(u)], f[root(u + T)]);
          res -= min(f[root(v)], f[root(v + T)]);
          Merge(u, v);
          Merge(u + T, v + T);
          res += min(f[root(u)], f[root(u + T)]);
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}
