#include <bits/stdc++.h>
using namespace std;
int n;
int a[300010], b[300010];
long long sa[300010], sb[300010];
int pra[300010], prb[300010], prab[300010];
map<pair<int, int>, int> f;
int calc(int x, int y) {
  if (f.count({x, y})) return f[{x, y}];
  if (x == 0 && y == 0) return 0;
  int now = 0;
  if (pra[x] >= prb[y]) {
    if (pra[x] != -1) now = max(now, calc(pra[x], y) + 1);
  } else {
    if (prb[y] != -1) now = max(now, calc(x, prb[y]) + 1);
  }
  if (prab[min(x, y)] != -1)
    now = max(now, calc(prab[min(x, y)], prab[min(x, y)]) + 1);
  return f[{x, y}] = now;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= n; ++i) {
    sa[i] = sa[i - 1] + a[i];
    sb[i] = sb[i - 1] + b[i];
  }
  memset(pra, -1, sizeof(pra));
  memset(prb, -1, sizeof(prb));
  memset(prab, -1, sizeof(prab));
  map<int, int> last;
  last[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (last.find(sa[i]) != last.end()) pra[i] = last[sa[i]];
    last[sa[i]] = i;
    pra[i] = max(pra[i], pra[i - 1]);
  }
  last.clear();
  last[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (last.find(sb[i]) != last.end()) prb[i] = last[sb[i]];
    last[sb[i]] = i;
    prb[i] = max(prb[i], prb[i - 1]);
  }
  last.clear();
  last[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (last.find(sa[i] + sb[i]) != last.end()) prab[i] = last[sa[i] + sb[i]];
    last[sa[i] + sb[i]] = i;
    prab[i] = max(prab[i], prab[i - 1]);
  }
  cout << calc(n, n);
}
