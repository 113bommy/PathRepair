#include <bits/stdc++.h>
using namespace std;
const long double pai = acos(-1.0L);
const long double eps = 1e-10;
const long long mod = 1e9 + 7;
const int MXN = 1e6 + 5;
vector<int> g[MXN], v;
int co[MXN];
int go[MXN];
void dfs(int now, int pr, int cg0, int cg1, int dis) {
  if (dis % 2 == 0) {
    if ((co[now] + cg0) % 2 != go[now]) v.push_back(now), cg1++;
  } else {
    if ((co[now] + cg1) % 2 != go[now]) v.push_back(now), cg0++;
  }
  for (auto i : g[now]) {
    if (i == pr) continue;
    dfs(i, now, cg0, cg1, dis + 1);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int sa, sb;
    scanf("%d %d", &sa, &sb);
    g[sa].push_back(sb);
    g[sb].push_back(sa);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &co[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &go[i]);
  dfs(1, -1, 0, 0, 0);
  cout << (int)v.size() << '\n';
  for (auto i : v) cout << i << '\n';
  return 0;
}
