#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const long long INF = (long long)1e18;
int n, m;
vector<pair<int, int> > e[N];
long long d[N], s[N];
bool vis[N];
int fa[N], sz[N];
void checkmax(long long &x, long long y) {
  if (y > x) {
    x = y;
  }
}
void dfs(int u, int f) {
  fa[u] = f;
  for (auto it : e[u]) {
    int v = it.first;
    int w = it.second;
    if (v != f) {
      s[v] = s[u] + w;
      dfs(v, u);
    }
  }
}
void go(int u, int f, long long &len) {
  sz[u] = 0;
  for (auto it : e[u]) {
    int v = it.first;
    int w = it.second;
    if (v != f && !vis[v]) {
      go(v, u, len);
      len = w;
      sz[u] += sz[v];
    }
  }
}
int main() {
  int a, b, c;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    e[a].push_back(make_pair(b, c));
    e[b].push_back(make_pair(a, c));
  }
  dfs(1, 0);
  vector<int> seq;
  int x = n;
  seq.push_back(x);
  vis[x] = true;
  while (x != 1) {
    seq.push_back(fa[x]);
    vis[fa[x]] = true;
    x = fa[x];
  }
  reverse(seq.begin(), seq.end());
  int flag = 0;
  for (int u : seq) {
    d[u] = 0;
    go(u, 0, d[u]);
    if (sz[u] > 1) {
      flag = 1;
    }
  }
  long long mx2 = -INF, mx1 = -INF, ret = -INF;
  int id = -1;
  for (int i = 0; i < (int)seq.size(); i++) {
    long long tmp1 = d[seq[i]] - s[seq[i]];
    if (d[seq[i]] > 0) {
      checkmax(ret, tmp1 + mx1);
    } else {
      if (id != -1 && id == i - 1 && d[seq[id]] > 0) {
        checkmax(ret, tmp1 + mx1);
      } else {
        checkmax(ret, tmp1 + mx2);
      }
    }
    if (i) {
      long long tmp2 = d[seq[i - 1]] + s[seq[i - 1]];
      if (tmp2 > mx2) {
        mx2 = tmp2;
      }
    }
    {
      long long tmp2 = d[seq[i]] + s[seq[i]];
      if (tmp2 > mx1) {
        id = i;
        mx1 = tmp2;
      }
    }
  }
  int q;
  while (m--) {
    scanf("%d", &x);
    if (flag || ret == -INF) {
      printf("%lld\n", s[n]);
    } else {
      printf("%lld\n", min(ret + x + s[n], s[n]));
    }
  }
  return 0;
}
