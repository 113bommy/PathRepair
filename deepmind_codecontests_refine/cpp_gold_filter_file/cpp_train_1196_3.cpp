#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
int n;
vector<int> ed[maxn];
int d[maxn], vis[maxn];
void dfs(int x, int fa) {
  vis[x] = 1;
  for (int i = 0; i < ed[x].size(); i++) {
    int k = ed[x][i];
    if (k == fa) continue;
    if (ed[k].size() <= 2) dfs(k, x);
  }
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ed[a].push_back(b);
    ed[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (ed[i].size() == 1) {
      dfs(i, -1);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    for (int j = 0; j < ed[i].size(); j++) {
      if (vis[ed[i][j]]) {
        d[i] = min(d[i] + 1, 2);
      }
    }
  }
  int fl = 1;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int cnt = 0;
      for (int j = 0; j < ed[i].size(); j++) {
        int k = ed[i][j];
        if (ed[k].size() - d[k] > 1 && !vis[k]) {
          cnt++;
        }
      }
      if (cnt > 2) {
        fl = 0;
      }
    }
  }
  if (fl) {
    puts("Yes");
  } else {
    puts("No");
  }
}
int main() {
  solve();
  return 0;
}
