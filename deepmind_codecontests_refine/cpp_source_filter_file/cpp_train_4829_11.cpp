#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, a[N], S[N];
vector<pair<int, int> > vec[N];
int t[N * 4][2], rev[N * 4];
void rever(int k) {
  swap(t[k][0], t[k][1]);
  rev[k] ^= 1;
}
void pushdown(int k) {
  if (!rev[k]) return;
  rever(k * 2);
  rever(k * 2 + 1);
  rev[k] = 0;
}
void build(int k, int l, int r) {
  t[k][1] = r - l + 1;
  if (l == r) return;
  int mid = (l + r) / 2;
  build(k * 2, l, mid);
  build(k * 2 + 1, mid + 1, r);
}
void change(int k, int l, int r, int x, int y) {
  if (x <= l && r <= y) return rever(k);
  pushdown(k);
  int mid = (l + r) / 2;
  if (x <= mid) change(k * 2, l, mid, x, y);
  if (y > mid) change(k * 2 + 1, mid + 1, r, x, y);
  t[k][0] = t[k * 2][0] + t[k * 2 + 1][0];
  t[k][1] = t[k * 2][1] + t[k * 2 + 1][1];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  build(1, 1, n);
  for (int i = (int)(1); i <= (int)(m); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = lower_bound(a + 1, a + n + 1, x) - a;
    y = lower_bound(a + 1, a + n + 1, y + 1) - a - 1;
    if (x < y) continue;
    S[x] ^= 1;
    S[y + 1] ^= 1;
    vec[x].push_back(pair<int, int>(x, y));
    vec[y + 1].push_back(pair<int, int>(x, y));
  }
  long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
  for (int i = (int)(1); i <= (int)(n); i++) {
    S[i] ^= S[i - 1];
    for (auto j : vec[i]) change(1, 1, n, j.first, j.second);
    int v = t[1][1];
    change(1, 1, n, i, i);
    v = min(v, t[1][1]);
    ans -= 1ll * v * (v - 1) / 2;
  }
  printf("%lld\n", ans);
}
