#include <bits/stdc++.h>
using namespace std;
int par[100000], rnk[100000], cnt[100000], D[100000], N;
int k, m;
int getRoot(int x) {
  if (par[x] == x) return x;
  return par[x] = getRoot(par[x]);
}
void unionRoot(int x, int y) {
  int r1 = getRoot(x), r2 = getRoot(y);
  if (r1 == r2) return;
  if (rnk[r1] > rnk[r2])
    par[r2] = r1, cnt[r1] += cnt[r2];
  else if (rnk[r1] < rnk[r2])
    par[r1] = r2, cnt[r2] += cnt[r1];
  else
    par[r2] = r1, rnk[r1]++, cnt[r1] += cnt[r1];
}
void initDsu() {
  memset(D, 0, sizeof(D));
  memset(par, 0, sizeof(par));
  memset(rnk, 0, sizeof(rnk));
  for (int i = 0; i <= N; i++) par[i] = i, rnk[i] = 1, cnt[i] = 1;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> k;
  initDsu();
  for (int i = 1; i <= k; i++) {
    int u, v;
    cin >> u >> v;
    unionRoot(u, v);
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    int r1 = getRoot(u), r2 = getRoot(v);
    if (r1 == r2) D[r1] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (!D[getRoot(i)]) ans = max(ans, cnt[getRoot(i)]);
  }
  cout << ans << "\n";
  return 0;
}
