#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> V[maxn], H[maxn];
int n, m;
long long a[maxn];
int SG[maxn];
int h[maxn];
int maxx = 0;
int dfs(int u) {
  if (SG[u] != -1) return SG[u];
  vector<int> tmp;
  for (auto v : V[u]) {
    tmp.push_back(dfs(v));
  }
  sort(tmp.begin(), tmp.end());
  int j = 0;
  for (int i = 0;; i++) {
    if (tmp.size() == 0 || tmp[j] != i || j >= tmp.size()) {
      SG[u] = i;
      break;
    }
    while (j < tmp.size() && tmp[j] == i) j++;
  }
  maxx = max(maxx, SG[u]);
  return SG[u];
}
int c[maxn];
void solve(int x) {
  for (auto i : H[x]) {
    if ((a[i] ^ h[x]) < a[i]) {
      a[i] = a[i] ^ h[x];
      for (auto j : V[i]) {
        if (c[SG[j]]) continue;
        c[SG[j]] = 1;
        a[j] ^= h[SG[j]];
      }
      break;
    }
  }
}
int main() {
  memset(SG, -1, sizeof(SG));
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    V[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (SG[i] == -1) dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    h[SG[i]] ^= a[i];
    H[SG[i]].push_back(i);
  }
  int p;
  int flag = 0;
  for (int i = maxx; i >= 0; i--) {
    if (h[i]) {
      flag = 1;
      p = i;
      solve(i);
      break;
    }
  }
  if (flag) {
    puts("WIN");
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
  } else
    puts("LOSE");
  return 0;
}
