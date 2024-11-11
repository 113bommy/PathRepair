#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
const int N = 4e5 + 5;
int n, h;
int sub[N];
int Mx[N][2];
int id[N][2];
int flag[N];
int ans[N];
vector<int> G[N];
int is[N];
void dfs(int u, int p = -1) {
  sub[u] = 1;
  is[u] = 0;
  flag[u] = 1;
  Mx[u][0] = Mx[u][1] = -1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == p) continue;
    dfs(v, u);
    sub[u] += sub[v];
    if (sub[v] > h) {
      if (sub[v] - Mx[v][0] <= h) {
        is[u]++;
      } else
        flag[u] = 0;
    }
    int o = Mx[v][0];
    if (sub[v] <= h) o = max(o, sub[v]);
    if (Mx[u][0] < o) {
      Mx[u][1] = Mx[u][0];
      id[u][1] = id[u][0];
      Mx[u][0] = o;
      id[u][0] = v;
    } else if (Mx[u][1] < o) {
      Mx[u][1] = o;
      id[u][1] = v;
    }
  }
}
void dfs2(int u, int p, int PM) {
  if (u > 1) {
    int o = PM;
    int os = n - sub[u];
    if (os - o > h) flag[u] = 0;
    if (os > h) is[u]++;
  }
  if (is[u] > 1 || flag[u] == 0) ans[u] = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == p) continue;
    int M = PM;
    if (id[u][0] != v) M = max(M, Mx[u][0]);
    if (id[u][1] != v) M = max(M, Mx[u][1]);
    if (n - sub[u] + 1 <= h) M = max(M, n - sub[u] + 1);
    dfs2(v, u, M);
  }
}
int main() {
  int u, v;
  cin >> n;
  h = n / 2;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) ans[i] = 1, flag[i] = 1;
  dfs(1, -1);
  dfs2(1, -1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
