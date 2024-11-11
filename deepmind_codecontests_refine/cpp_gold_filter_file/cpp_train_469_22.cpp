#include <bits/stdc++.h>
using namespace std;
vector<int> G[100005], E[100005];
long long S[100005], C[100005], ans;
int n, a[100005], f[100005], w[100005], st[20][100005];
int query(int l, int r) {
  int t = (int)(log2(r - l + 1));
  int x = st[t][l], y = st[t][r - (1 << t) + 1];
  return a[x] < a[y] ? y : x;
}
void dfs(int t) {
  int i;
  if (t != n) ans += S[t] + C[t] + a[t] - t;
  for (i = 0; i < G[t].size(); i++) {
    C[G[t][i]] = C[t] + E[t][i];
    S[G[t][i]] = S[t] + C[t] + E[t][i];
    dfs(G[t][i]);
  }
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i < n; i++) scanf("%d", &a[i]), st[0][i] = i;
  a[n] = n + 1, st[0][n] = n;
  for (i = 1; i < 20; i++)
    for (j = 1; j <= n; j++) {
      st[i][j] = st[i - 1][j];
      if (j + (1 << (i - 1)) <= n &&
          a[st[i][j]] < a[st[i - 1][j + (1 << (i - 1))]])
        st[i][j] = st[i - 1][j + (1 << (i - 1))];
    }
  for (i = 1; i < n; i++) {
    f[i] = query(i + 1, a[i]);
    w[i] = a[f[i]] - a[i];
    if (f[i] == n) w[i] = 0;
  }
  for (i = 1; i < n; i++) {
    G[f[i]].push_back(i);
    E[f[i]].push_back(w[i]);
  }
  dfs(n);
  cout << ans;
  return 0;
}
