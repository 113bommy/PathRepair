#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 1, maxm = 100000 + 1;
int x[maxm], y[maxm], w[maxm], sig[maxm], ance[maxn], ans[maxn];
int n, m, k, tot, cnt, captedge;
double l, r, mid;
bool cmp(int a, int b) {
  return (w[a] + (x[a] == 1) * mid) < (w[b] + (x[b] == 1) * mid);
}
int findance(int x) {
  if (x == ance[x])
    return x;
  else
    return ance[x] = findance(ance[x]);
}
void Kruskal(bool flag) {
  cnt = captedge = 0;
  for (int i = 1; i <= n; i++) ance[i] = i;
  sort(sig, sig + m, cmp);
  for (int i = 0; i < m; i++) {
    if (cnt + 1 == n) return;
    int j = sig[i];
    int u = findance(x[j]), v = findance(y[j]);
    if ((u != v) && (flag || (captedge + (x[j] == 1)) <= k)) {
      ance[u] = v;
      ans[cnt++] = j;
      if (x[j] == 1) captedge++;
    }
  }
}
int main() {
  cin >> n >> m >> k;
  tot = 0;
  for (int i = 0; i < m; i++) {
    sig[i] = i;
    cin >> x[i] >> y[i] >> w[i];
    if (x[i] > y[i]) swap(x[i], y[i]);
    if (x[i] == 1) tot++;
  }
  if ((k > tot) || (k == 0 && n > 1)) {
    cout << "-1" << endl;
    return 0;
  }
  cnt = 0;
  Kruskal(1);
  if (cnt != (n - 1)) {
    cout << "-1" << endl;
    return 0;
  }
  l = (-1) * 100000.0;
  r = 100000.0;
  while ((l + 1e-1 < r) && (captedge != k)) {
    mid = (l + r) / 2.0;
    Kruskal(1);
    if (captedge < k)
      r = mid;
    else
      l = mid;
  }
  if (captedge != k) mid = (l + r) / 2.0;
  Kruskal(0);
  cout << n - 1 << endl;
  if (cnt >= 1) cout << ans[0] + 1;
  for (int i = 1; i < cnt; i++) cout << " " << ans[i] + 1;
  cout << endl;
  return 0;
}
