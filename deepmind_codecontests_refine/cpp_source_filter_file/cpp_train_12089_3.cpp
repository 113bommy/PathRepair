#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, q;
char A[maxn];
int m, sa[maxn], rk[maxn], ht[maxn], tp[maxn], bf[maxn], buk[maxn], lg[maxn],
    st[18][maxn];
void radix_sort() {
  memset(buk, 0, (m + 1) << 2);
  for (int i = (1), iend = (n); i <= iend; ++i) buk[bf[i] = rk[tp[i]]]++;
  for (int i = (1), iend = (m); i <= iend; ++i) buk[i] += buk[i - 1];
  for (int i = (n), iend = (1); i >= iend; --i) sa[buk[bf[i]]--] = tp[i];
}
void suffix_sort() {
  m = 150;
  for (int i = (1), iend = (n); i <= iend; ++i) rk[i] = A[i], tp[i] = i;
  radix_sort();
  for (int k = 1; k <= n; k <<= 1) {
    int num = 0;
    for (int i = (n), iend = (n - k + 1); i >= iend; --i) tp[++num] = i;
    for (int i = (1), iend = (n); i <= iend; ++i)
      if (sa[i] > k) tp[++num] = sa[i] - k;
    radix_sort();
    swap(rk, tp), rk[sa[1]] = 1, num = 1;
    for (int i = (2), iend = (n); i <= iend; ++i)
      rk[sa[i]] = num +=
          tp[sa[i]] != tp[sa[i - 1]] || tp[sa[i] + k] != tp[sa[i - 1] + k];
    if (n == num) break;
    m = num;
  }
  for (int i = 1, j = 0; i <= n; i++) {
    if (j) j--;
    while (A[i + j] == A[sa[rk[i] - 1] + j]) j++;
    ht[rk[i]] = j;
  }
  for (int i = (2), iend = (n); i <= iend; ++i) lg[i] = lg[i >> 1] + 1;
  for (int i = (1), iend = (n); i <= iend; ++i) st[0][i] = ht[i];
  for (int i = (1), iend = (17); i <= iend; ++i)
    for (int j = (1), jend = (n - (1 << i) + 1); j <= jend; ++j)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
int qmin(int l, int r) {
  int k = lg[r - l + 1];
  return min(st[k][l], st[k][r - (1 << k) + 1]);
}
int main() {
  scanf("%d%d%s", &n, &q, A + 1);
  suffix_sort();
  while (q--) {
    static int st[maxn], lef[maxn], rig[maxn], X[maxn], Y[maxn], V[maxn],
        val[maxn];
    int top = 0;
    int cx, cy;
    scanf("%d%d", &cx, &cy);
    int sz = cx + cy;
    for (int i = (1), iend = (cx); i <= iend; ++i)
      scanf("%d", &X[i]), V[i] = X[i] = rk[X[i]];
    for (int i = (1), iend = (cy); i <= iend; ++i)
      scanf("%d", &Y[i]), V[cx + i] = Y[i] = rk[Y[i]];
    sort(X + 1, X + cx + 1), sort(Y + 1, Y + cy + 1), sort(V + 1, V + sz + 1),
        sz = unique(V + 1, V + sz + 1) - V - 1;
    long long ans = 0;
    set<int> vis;
    for (int i = (1), iend = (cx); i <= iend; ++i) vis.insert(X[i]);
    for (int i = (1), iend = (cy); i <= iend; ++i)
      if (vis.count(Y[i])) ans += n - sa[Y[i]] + 1;
    set<int> visy;
    for (int i = (1), iend = (cy); i <= iend; ++i) visy.insert(Y[i]);
    for (int i = (2), iend = (sz); i <= iend; ++i)
      val[i] = qmin(V[i - 1] + 1, V[i]);
    st[0] = 1;
    for (int i = (2), iend = (sz); i <= iend; ++i) {
      while (top && val[st[top]] > val[i]) top--;
      lef[i] = st[top] + 1, st[++top] = i;
    }
    st[top = 0] = sz + 1;
    for (int i = (sz), iend = (2); i >= iend; --i) {
      while (top && val[st[top]] >= val[i]) top--;
      rig[i] = st[top] - 1, st[++top] = i;
    }
    for (int i = (2), iend = (sz); i <= iend; ++i) {
      long long c1 = 1ll *
                     (upper_bound(X + 1, X + cx + 1, V[i - 1]) -
                      lower_bound(X + 1, X + cx + 1, V[lef[i] - 1])) *
                     (upper_bound(Y + 1, Y + cy + 1, V[rig[i]]) -
                      lower_bound(Y + 1, Y + cy + 1, V[i]));
      long long c2 = 1ll *
                     (upper_bound(X + 1, X + cx + 1, V[rig[i]]) -
                      lower_bound(X + 1, X + cx + 1, V[i])) *
                     (upper_bound(Y + 1, Y + cy + 1, V[i - 1]) -
                      lower_bound(Y + 1, Y + cy + 1, V[lef[i] - 1]));
      ans += 1ll * val[i] * (c1 + c2);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
