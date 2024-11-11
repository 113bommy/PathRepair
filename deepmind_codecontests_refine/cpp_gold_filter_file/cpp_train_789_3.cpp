#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (long long)a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int pow(int a, int b, int c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    a = 1LL * a * a % c;
    b >>= 1;
  }
  return ans;
}
int a[300010];
vector<pair<int, int> > g[300010];
int vis[300010], rt;
vector<int> res;
void dfs(int u) {
  int K = -1;
  for (auto o : g[u]) {
    if (vis[o.second]) continue;
    vis[o.second] = 1;
    int v = o.first;
    dfs(v);
    if (a[v] && a[v] != -1) {
      if (a[u] != -1) a[u] ^= 1;
      res.push_back(o.second);
      a[v] ^= 1;
    } else if (a[v] == -1) {
      K = o.second;
    }
  }
  if (u == rt) {
    if (a[u] != -1 && a[u]) {
      if (K != -1) a[u] ^= 1;
    }
  }
}
int main() {
  int j, k, i, T, ca = 0, n, m, K;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &j, &k);
    j--, k--;
    g[j].push_back({k, i});
    g[k].push_back({j, i});
  }
  int sz = 0;
  K = -1;
  for (int i = 0; i < n; i++)
    if (a[i] == 1)
      sz++;
    else if (a[i] == -1)
      K = i;
  if (sz & 1) {
    if (K == -1) {
      puts("-1");
      return 0;
    }
  }
  if (K != -1)
    rt = K, dfs(K);
  else
    rt = 0, dfs(0);
  if (a[rt] != -1 && a[rt])
    puts("-1");
  else {
    printf("%d\n", (int)(res.size()));
    sort(res.begin(), res.end());
    for (auto first : res) printf("%d\n", first + 1);
  }
  return 0;
}
