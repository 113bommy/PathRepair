#include <bits/stdc++.h>
using namespace std;
inline int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
int u[400000], v[400000], w[400000], p[400000], res[400000], sz[400000];
int n, m, odd;
pair<int, int> e[400000];
vector<int> vz, vp;
void add(int x) {
  int a = u[x], b = v[x];
  while (p[a]) a = p[a];
  while (p[b]) b = p[b];
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  if (sz[a] % 2 == 1 && sz[b] % 2 == 1) {
    odd -= 2;
    vz.push_back(2);
  } else
    vz.push_back(0);
  p[b] = a;
  sz[a] += sz[b];
  vp.push_back(b);
}
void rollback(int ver) {
  while (vz.size() > ver) {
    int b = vp.back();
    vp.pop_back();
    sz[p[b]] -= sz[b];
    p[b] = 0;
    odd += vz.back();
    vz.pop_back();
  }
}
void f(int l, int r, int lo, int hi) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int ans = -1;
  int ver = vz.size();
  for (int i = l; i <= mid; i++)
    if (w[i] < e[lo].first) add(i);
  for (int i = lo; i <= hi; i++)
    if (e[i].second <= mid) {
      add(e[i].second);
      if (odd == 0) {
        ans = i;
        break;
      }
    }
  rollback(ver);
  if (ans < 0) {
    for (int i = l; i <= mid; i++)
      if (w[i] < e[lo].first) add(i);
    f(mid + 1, r, lo, hi);
    rollback(ver);
    return;
  }
  res[mid] = e[ans].first;
  for (int i = lo; i < ans; i++)
    if (e[i].second < l) add(e[i].second);
  f(l, mid - 1, ans, hi);
  rollback(ver);
  for (int i = l; i <= mid; i++)
    if (w[i] < e[lo].first) add(i);
  f(mid + 1, r, lo, ans);
  rollback(ver);
}
int main() {
  memset(res, -1, sizeof(res));
  odd = n = ri();
  m = ri();
  for (int i = 1; i <= n; i++) sz[i] = 1;
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    e[i] = pair<int, int>(w[i], i);
  }
  sort(e, e + m);
  f(0, m - 1, 0, m - 1);
  for (int i = 0; i < m; i++) cout << res[i] << endl;
  return 0;
}
