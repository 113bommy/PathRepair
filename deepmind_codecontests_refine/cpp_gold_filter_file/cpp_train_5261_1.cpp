#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 100;
const double eps = 1e-9;
struct TSegment {
  int l, r, id;
};
bool cmp(TSegment a, TSegment b) {
  if (a.l != b.l)
    return a.l > b.l;
  else
    return a.r > b.r;
}
int n;
TSegment a[MAXN];
map<int, int> f;
int ans[MAXN], tmp[MAXN], tree[2 * MAXN], vmax;
int res = 0;
void update(int pos, int v) {
  for (; pos <= vmax; pos += pos & -pos) tree[pos] += v;
}
int get(int pos) {
  int res = 0;
  for (; pos > 0; pos -= pos & -pos) res += tree[pos];
  return res;
}
int main() {
  cout << setprecision(10) << fixed;
  scanf("%d", &n);
  for (int i = 1, _b = (n); i <= _b; i++) {
    scanf("%d %d", &a[i].l, &a[i].r);
    tmp[i * 2 - 1] = a[i].l;
    tmp[i * 2] = a[i].r;
    a[i].id = i;
  }
  sort(tmp + 1, tmp + 1 + 2 * n);
  sort(a + 1, a + 1 + n, cmp);
  tmp[0] = -INF;
  for (int i = 1, _b = (2 * n); i <= _b; i++) {
    f[tmp[i]] = f[tmp[i - 1]] + 1;
  }
  for (int i = 1, _b = (n); i <= _b; i++)
    a[i].l = f[a[i].l], a[i].r = f[a[i].r];
  vmax = f[tmp[2 * n]];
  for (int i = 1, _b = (n); i <= _b; i++) {
    res = 0;
    ans[a[i].id] = get(a[i].r);
    update(a[i].r, 1);
  }
  for (int i = 1, _b = (n); i <= _b; i++) printf("%d\n", ans[i]);
  return 0;
}
