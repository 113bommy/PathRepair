#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long sum, pl;
} t[200086 << 2];
inline void up(int x) { t[x].sum = max(t[(x << 1)].sum, t[(x << 1 | 1)].sum); }
inline void add(int x, long long y) { t[x].sum += y, t[x].pl += y; }
inline void down(int x) {
  if (t[x].pl) {
    add((x << 1), t[x].pl), add((x << 1 | 1), t[x].pl);
    t[x].pl = 0;
  }
}
void modify(int x, int l, int r, int ll, int rr, int d) {
  if (ll <= l && r <= rr) {
    add(x, d);
    return;
  }
  down(x);
  int mid = l + r >> 1;
  if (mid >= ll) modify((x << 1), l, mid, ll, rr, d);
  if (mid < rr) modify((x << 1 | 1), mid + 1, r, ll, rr, d);
  up(x);
}
long long query(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) return t[x].sum;
  down(x);
  int mid = l + r >> 1;
  long long sum = 1ll << 63;
  if (mid >= ll) sum = max(sum, query((x << 1), l, mid, ll, rr));
  if (mid < rr) sum = max(sum, query((x << 1 | 1), mid + 1, r, ll, rr));
  return sum;
}
int n, m;
int c[200086];
int x, y, z;
vector<pair<int, int> > v[200086];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &x, &y, &z), v[y].push_back({x, z});
  for (int i = 1; i <= n; i++) {
    modify(1, 0, n, i, i, query(1, 0, n, 0, i - 1));
    for (int j = 0; j < v[i].size(); j++) {
      modify(1, 0, n, 0, v[i][j].first - 1, v[i][j].second);
    }
    modify(1, 0, n, 0, i - 1, -c[i]);
  }
  printf("%lld", t[1].sum);
}
