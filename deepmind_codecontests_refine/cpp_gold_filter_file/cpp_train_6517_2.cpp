#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct Fenwick {
  int c[N];
  Fenwick() { memset(c, 0, sizeof(c)); }
  void upd(int i, int v) {
    for (; i < N; i += (i) & (-i)) c[i] += v;
  }
  int sum(int i) {
    int ret = 0;
    for (; i; i -= (i) & (-i)) ret += c[i];
    return ret;
  }
} F;
struct P {
  int x, id;
  bool operator<(const P& r) const { return x != r.x ? x < r.x : id < r.id; }
} p[N];
int n;
int dist(int a, int b) {
  if (a > b) return dist(a, n) + dist(0, b);
  return b - F.sum(b) - (a - F.sum(a));
}
int main() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) cin >> p[i].x, p[i].id = i;
  sort(p + 1, p + 1 + n);
  long long ans = 0;
  int i = 1, j = 1, cur = 0;
  while (j <= n) {
    while (j <= n && p[i].x == p[j].x) ++j;
    int k = upper_bound(p + i, p + j, P{p[i].x, cur}) - p;
    int l = k == j ? p[i].id : p[k].id;
    int r = k == i ? p[j - 1].id : p[k - 1].id;
    ans += dist(cur, l) + dist(l, r);
    cur = r;
    for (int w = i; w < j; w++) F.upd(p[w].id, 1);
    i = j;
  }
  cout << ans << endl;
  return 0;
}
