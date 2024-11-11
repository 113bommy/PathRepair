#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
struct pi {
  int le, ri;
  int mi;
  int ma;
  int lazy;
  long long sum;
} pp[maxn << 2];
void build(int tot, int l, int r) {
  pp[tot].le = l;
  pp[tot].ri = r;
  pp[tot].mi = l;
  pp[tot].ma = r;
  pp[tot].lazy = 0;
  pp[tot].sum = l;
  if (l == r) return;
  build(2 * tot, l, (l + r) / 2);
  build(2 * tot + 1, (l + r) / 2 + 1, r);
  pp[tot].sum = pp[2 * tot].sum + pp[2 * tot + 1].sum;
}
void push(int tot) {
  if (pp[tot].lazy) {
    pp[tot].mi = pp[tot].ma = pp[tot].lazy;
    pp[tot].sum = (long long)pp[tot].lazy * (pp[tot].ri - pp[tot].le + 1);
    pp[2 * tot].lazy = pp[2 * tot + 1].lazy = pp[tot].lazy;
    pp[tot].lazy = 0;
  }
}
int getmi(int tot) {
  if (pp[tot].lazy) return pp[tot].lazy;
  return pp[tot].mi;
}
int getma(int tot) {
  if (pp[tot].lazy) return pp[tot].lazy;
  return pp[tot].ma;
}
long long getsum(int tot) {
  if (pp[tot].lazy)
    return (long long)pp[tot].lazy * (pp[tot].ri - pp[tot].le + 1);
  return pp[tot].sum;
}
void pushup(int tot) {
  pp[tot].ma = max(getma(2 * tot), getma(2 * tot + 1));
  pp[tot].mi = min(getmi(2 * tot), getmi(2 * tot + 1));
  pp[tot].sum = getsum(2 * tot) + getsum(2 * tot + 1);
}
void merg(int tot, int l, int r, int p) {
  if (l > r) return;
  push(tot);
  if (pp[tot].mi >= p) return;
  if (pp[tot].le >= l && pp[tot].ri <= r) {
    if (pp[tot].ma <= p)
      pp[tot].lazy = p;
    else {
      merg(2 * tot, l, r, p);
      merg(2 * tot + 1, l, r, p);
      pushup(tot);
    }
    return;
  }
  int mid = (pp[tot].le + pp[tot].ri) / 2;
  if (l <= mid) merg(2 * tot, l, r, p);
  if (r > mid) merg(2 * tot + 1, l, r, p);
  pushup(tot);
}
int query(int tot, int x) {
  if (pp[tot].lazy) return pp[tot].lazy;
  int mid = (pp[tot].le + pp[tot].ri) / 2;
  if (x <= mid)
    return query(2 * tot, x);
  else
    return query(2 * tot + 1, x);
}
int x[maxn];
long long h[maxn];
vector<int> g;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    x[p] = i;
  }
  build(1, 1, n);
  for (int i = maxn - 1; i >= 1; i--) {
    g.clear();
    for (int j = i + 1; j < maxn; j += i + 1) {
      if (x[j] == 0) continue;
      g.push_back(x[j]);
    }
    sort(g.begin(), g.end());
    int p = g.size();
    if (p > 1) {
      merg(1, g[1] + 1, n, n + 1);
      merg(1, g[0] + 1, g[1], g[p - 1]);
      merg(1, 1, g[0], g[p - 2]);
    }
    h[i] = (long long)(n + 1) * n - getsum(1);
  }
  h[0] = 3;
  long long ans = 0;
  for (int i = 1; i < maxn; i++) {
    ans += (h[i] - h[i - 1]) * i;
  }
  cout << ans << endl;
}
