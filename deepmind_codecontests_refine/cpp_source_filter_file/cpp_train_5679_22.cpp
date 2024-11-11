#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline string get() {
  char ch[1000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 21;
const int maxn = 2e5 + 10;
const int INF = 1e9;
const int SQ = 317;
vector<int> g[maxn];
int l[maxn], r[maxn], s[maxn], t[maxn];
vector<int> qu[maxn];
int di[2000][2000];
int v[maxn], u[maxn];
int res[maxn];
int32_t main() {
  int n = in(), m = in(), q = in();
  for (int i = 0; i < m; i++) {
    v[i] = in(), u[i] = in();
    g[v[i]].push_back(u[i]), g[u[i]].push_back(v[i]);
  }
  for (int i = 0; i < q; i++) {
    l[i] = in() - 1, r[i] = in() - 1, s[i] = in(), t[i] = in();
    qu[l[i]].push_back(i);
  }
  for (int i = 0; i < 1e3 + 10; i++)
    for (int j = 0; j < 1e3 + 10; j++) di[i][j] = 1e9;
  for (int i = m - 1; i >= 0; i--) {
    di[v[i]][u[i]] = di[u[i]][v[i]] = true;
    for (int x = 1; x <= n; x++) {
      di[v[i]][x] = min(di[v[i]][x], di[u[i]][x]);
      di[u[i]][x] = min(di[u[i]][x], di[v[i]][x]);
    }
    for (auto x : qu[i]) {
      if (di[s[x]][t[x]] <= r[x]) {
        res[x] = true;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    if (res[i])
      printf("Yes\n");
    else
      printf("No\n");
  }
}
