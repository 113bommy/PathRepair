#include <bits/stdc++.h>
using namespace std;
typedef struct edged {
  int i, u, v, w;
} edges;
edges edge[100010];
double first, last, mid = 0;
int n, m, k, ct = 0, par[100010], len_mst, ans = 0, ansr[100010];
int val(edges x) { return (x.u == 1) * mid; }
bool com(edges x, edges y) {
  double a = x.w, b = y.w;
  if (x.u == 1) a += mid;
  if (y.u == 1) b += mid;
  return a < b;
}
int find(int s) {
  if (par[s] == s) return s;
  return par[s] = find(par[s]);
}
void kruskals(int fl) {
  sort(edge, edge + m, com);
  len_mst = ct = ans = 0;
  for (int i = 0; i <= n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int u = edge[i].u, v = edge[i].v, w = edge[i].w;
    int p1 = find(u), p2 = find(v);
    if (p1 != p2 && (fl == 1 || (ct + (u == 1)) <= k)) {
      par[p1] = p2;
      ct += u == 1;
      ans += w;
      ansr[len_mst++] = edge[i].i;
    }
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge[i].i = i + 1;
    edge[i].u = min(u, v);
    edge[i].v = max(u, v);
    edge[i].w = w;
    if (edge[i].u == 1) ct++;
  }
  if (ct < k || (n > 1 && k == 0)) {
    cout << -1 << endl;
    return 0;
  }
  kruskals(1);
  if (len_mst < n - 1) {
    cout << -1 << endl;
    return 0;
  }
  first = -1e6;
  last = -first;
  while (first + 0.1 < last && ct != k) {
    mid = (first + last) / 2;
    kruskals(1);
    if (ct < k)
      last = mid;
    else
      first = mid;
  }
  if (ct != k) mid = (first + last) / 2;
  kruskals(0);
  cout << len_mst << endl;
  for (int i = 0; i < len_mst; i++) cout << ansr[i] << " ";
  cout << endl;
}
