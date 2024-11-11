#include <bits/stdc++.h>
using namespace std;
inline long long sqr(long long x) { return x * x; }
struct data {
  int x, cnt;
  data(int _x = 0, int _cnt = 0) : x(_x), cnt(_cnt) {}
};
;
const int N = 1e5 + 5;
int sa[N], ra[N], rb[N], lcp[N], gap;
int n, sum[N];
data tree[4 * N];
char s[N];
void buildtree(int k, int l, int r) {
  if (l > r) return;
  if (l == r) {
    tree[k].x = sum[l];
    tree[k].cnt = 1;
    return;
  }
  int mid = (l + r) >> 1;
  buildtree(k * 2, l, mid);
  buildtree(k * 2 + 1, mid + 1, r);
  int x = tree[k * 2].x, y = tree[k * 2 + 1].x;
  if (x < y)
    tree[k].x = x, tree[k].cnt = tree[k * 2].cnt;
  else
    tree[k].x = y, tree[k].cnt = tree[k * 2 + 1].cnt;
  if (x == y) tree[k].cnt += tree[k * 2].cnt;
}
inline data query(int k, int l, int r, int L, int R) {
  if (l > r || l > R || r < L) return data(1e9 + 7, 0);
  if (L <= l && r <= R) return tree[k];
  int mid = (l + r) >> 1;
  data p1 = query(k * 2, l, mid, L, R);
  data p2 = query(k * 2 + 1, mid + 1, r, L, R);
  if (p1.x < p2.x)
    return p1;
  else if (p1.x > p2.x)
    return p2;
  return data(p1.x, p1.cnt + p2.cnt);
}
inline bool cmp(int x, int y) {
  if (ra[x] != ra[y]) return ra[x] < ra[y];
  return ra[x + gap] < ra[y + gap];
}
void buildSA() {
  for (int i = (1), _b = (n); i <= _b; ++i) sa[i] = i, ra[i] = s[i];
  for (gap = 1; gap <= n; gap *= 2) {
    sort(sa + 1, sa + n + 1, cmp);
    for (int i = (1), _b = (n); i <= _b; ++i)
      rb[sa[i]] = rb[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
    for (int i = (1), _b = (n); i <= _b; ++i) ra[i] = rb[i];
    if (ra[sa[n]] == n) break;
  }
}
void buildLCP() {
  int k = 0;
  for (int i = (1), _b = (n); i <= _b; ++i) {
    int p = ra[i], j = sa[p - 1];
    while (s[i + k] == s[j + k]) ++k;
    lcp[p] = k;
    if (k) --k;
  }
}
int main() {
  int t = 1;
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = (1), _b = (n); i <= _b; ++i)
      sum[i] = sum[i - 1] + (s[i] == ')' ? -1 : 1);
    buildSA();
    buildLCP();
    buildtree(1, 1, n);
    long long res = 0, total = 0;
    for (int i = (1), _b = (n); i <= _b; ++i) {
      int lo = sa[i], hi = n, ans = 0, mid;
      while (lo <= hi) {
        mid = (lo + hi) >> 1;
        int tmpx = query(1, 1, n, sa[i], mid).x;
        if (tmpx < sum[sa[i] - 1])
          hi = mid - 1;
        else
          ans = mid, lo = mid + 1;
      }
      if (ans) {
        data tmp = query(1, 1, n, sa[i], ans);
        if (tmp.x == sum[sa[i] - 1]) total += (long long)tmp.cnt;
        if (i > 1) {
          tmp = query(1, 1, n, sa[i], min(ans, sa[i] + lcp[i] - 1));
          if (tmp.x == sum[sa[i] - 1]) res += (long long)tmp.cnt;
        }
      }
    }
    printf("%lld\n", total - res);
  }
  return 0;
}
