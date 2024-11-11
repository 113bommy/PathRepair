#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
int n, m, z[1001000], y[1001000], a[1001000];
string p;
bool ok(int x, int y) {
  if (x > y) swap(x, y);
  if (y - x >= (int)p.size()) return true;
  int ind = y - x;
  int need = x + (int)p.size() - 1 - y + 1;
  return z[ind] >= need;
}
void precalc() {
  for (int i = 1, l = 0, r = 0; i < (int)p.size(); ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < (int)p.size() && p[z[i]] == p[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}
void add(int id) {
  int l = y[id];
  int r = y[id] + (int)p.size();
  a[l]++;
  a[r]--;
}
int main() {
  scanf("%d %d\n", &n, &m);
  getline(cin, p);
  for (int i = 0; i < m; i++) scanf("%d", y + i);
  precalc();
  int ans = 1;
  for (int i = 0; i < m - 1; i++) {
    if (ok(y[i], y[i + 1]))
      add(i);
    else {
      ans = 0;
    }
  }
  add(m - 1);
  int sum = 0;
  for (int i = 0; i <= n; i++) {
    sum += a[i];
    a[i] = sum;
  }
  for (int i = 1; i <= n; i++) {
    if (!a[i]) ans = 1ll * ans * 26 % mod;
  }
  printf("%d\n", ans);
  return 0;
}
