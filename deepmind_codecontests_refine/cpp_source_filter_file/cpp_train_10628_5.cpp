#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int mod = int(1e9) + 7;
int n, m, second, te, N, b[200100];
int t[4 * 200100];
pair<int, int> a[200100];
map<int, int> id;
void upd(int v, int l, int r, int pos, int val) {
  if (l == r) {
    t[v] = (t[v] + val) % mod;
    return;
  }
  int tm = (l + r) / 2;
  if (pos <= tm)
    upd(v + v, l, tm, pos, val);
  else
    upd(v + v + 1, tm + 1, r, pos, val);
  t[v] = (t[v + v] + t[v + v + 1]) % mod;
}
int get(int v, int l, int r, int x, int y) {
  if (x > r || l > y) return 0;
  if (x <= l && r <= y) return t[v];
  int tm = (l + r) / 2;
  int p1 = get(v + v, l, tm, x, y);
  int p2 = get(v + v + 1, tm + 1, r, x, y);
  return (p1 + p2) % mod;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].second >> a[i].first;
    b[++N] = a[i].second;
    b[++N] = a[i].first;
    b[++N] = a[i].first - 1;
    a[i].second = -a[i].second;
  }
  b[++N] = n;
  N++;
  sort(b, b + N);
  int nz = unique(b, b + N) - (b);
  for (int i = 0; i < nz; i++) {
    id[b[i]] = i;
  }
  sort(a + 1, a + 1 + m);
  upd(1, 0, nz - 1, id[0], 1);
  for (int i = 1; i <= m; i++) {
    second = -a[i].second;
    te = a[i].first;
    int z = get(1, 0, nz - 1, id[second], id[te - 1]);
    upd(1, 0, nz - 1, id[te], z);
  }
  int z = get(1, 0, nz - 1, id[n], id[n]);
  printf("%d", z);
  return 0;
}
