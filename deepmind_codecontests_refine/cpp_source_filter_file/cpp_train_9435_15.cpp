#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, m, a[N], l[N], r[N];
bool ok, vis[N];
void load() {}
bool check(int a, int b) {
  if (a == b - 1) return 1;
  if (a == b + 1) return 1;
  if (a == b - m) return 1;
  if (a == b + m) return 1;
  return 0;
}
void dfs(int p) {
  if (ok) return;
  if (p == n * m + 1) {
    cout << "YES" << endl;
    for (int i = 1; i <= n * m; ++i) {
      cout << a[i] << " ";
      if (i % m == 0) cout << endl;
    }
    ok = 1;
    return;
  }
  for (int i = r[0]; i <= n * m; i = r[i]) {
    if (ok) return;
    if (vis[i]) continue;
    if (p - (p / m) * m > 1 && check(i, a[p - 1])) continue;
    if (p > m && check(i, a[p - m])) continue;
    vis[i] = 1;
    int t1 = l[i];
    int t2 = r[i];
    r[t1] = t2;
    l[t2] = t1;
    a[p] = i;
    dfs(p + 1);
    vis[i] = 0;
    l[t2] = i;
    r[t1] = i;
  }
  return;
}
void process() {
  cin >> n >> m;
  for (int i = 0; i <= n * m; ++i) l[i] = i - 1, r[i] = i + 1;
  ok = 0;
  dfs(1);
  if (!ok) cout << "NO";
  return;
}
int main() {
  load();
  process();
  return 0;
}
