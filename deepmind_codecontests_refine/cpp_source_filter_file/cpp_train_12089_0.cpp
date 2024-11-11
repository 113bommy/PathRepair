#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, qn, qm;
int st[19][N];
int c[N], x[N], y[N], sa[N], height[N], sA[N], sB[N];
char s[N];
inline int lcp(int l, int r) {
  if (++l > r) return n - sa[r] + 1;
  const int g = (31 - __builtin_clz(r - l + 1));
  return min(st[g][l], st[g][r - (1 << g) + 1]);
}
void sort_() {
  int m = 256;
  for (int i = 1; i <= n; ++i) ++c[x[i] = s[i]];
  for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
  for (int i = n; i; --i) sa[c[x[i]]--] = i;
  for (int k = 1; k <= n; k <<= 1) {
    int p = 0;
    for (int i = n - k + 1; i <= n; ++i) y[++p] = i;
    for (int i = 1; i <= n; ++i)
      if (sa[i] > k) y[++p] = sa[i] - k;
    for (int i = 1; i <= m; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) ++c[x[i]];
    for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
    for (int i = n; i; --i) sa[c[x[y[i]]]--] = y[i];
    swap(x, y);
    x[sa[p = 1]] = 1;
    for (int i = 2; i <= n; ++i)
      x[sa[i]] =
          (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? p
                                                                        : ++p);
    if (p == n) break;
    m = p;
  }
  for (int i = 1, k = 0; i <= n; ++i)
    if (x[i] != 1) {
      k -= !!k;
      int j = sa[x[i] - 1];
      while (s[i + k] == s[j + k]) ++k;
      height[x[i]] = k;
    }
  for (int i = 1; i <= n; ++i) st[0][i] = height[i];
  for (int j = 1; j < 19; ++j)
    for (int i = 1; i + (1 << j - 1) <= n; ++i)
      st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
}
namespace sgt {
long long d[N << 2];
int tag[N << 2];
void build(int l, int r, int o) {
  d[o] = 0, tag[o] = -1;
  if (l < r) {
    const int mid = l + r >> 1;
    build(l, mid, o << 1), build(mid + 1, r, o << 1 | 1);
  }
}
inline void pushdown(int o, int len) {
  if (tag[o] == -1) return;
  int& x = tag[o];
  tag[o << 1] = tag[o << 1 | 1] = x;
  d[o << 1] = (len + 1LL >> 1) * x;
  d[o << 1 | 1] = (len >> 1) * (long long)x;
  x = -1;
}
void modify(int l, int r, int o, const int& L, const int& R, const int& v) {
  if (L <= l && r <= R) {
    d[o] = (r - l + 1LL) * v;
    tag[o] = v;
  } else {
    pushdown(o, r - l + 1);
    const int mid = l + r >> 1;
    if (L <= mid) modify(l, mid, o << 1, L, R, v);
    if (mid < R) modify(mid + 1, r, o << 1 | 1, L, R, v);
    d[o] = d[o << 1] + d[o << 1 | 1];
  }
}
}  // namespace sgt
int main() {
  scanf("%d%d%s", &n, &q, s + 1);
  sort_();
  while (q--) {
    scanf("%d%d", &qn, &qm);
    for (int i = 1, d; i <= qn; ++i) scanf("%d", &d), sA[i] = x[d];
    for (int i = 1, d; i <= qm; ++i) scanf("%d", &d), sB[i] = x[d];
    long long ans = 0;
    sort(sA + 1, sA + qn + 1), sort(sB + 1, sB + qm + 1);
    sgt::build(1, qm, 1);
    for (int i = 1, it = 1; i <= qn; ++i) {
      if (it > 1) {
        int k = lcp(sB[it - 1], sA[i]);
        int l = 1, r = it - 1, s = it - 1;
        while (l <= r) {
          const int mid = l + r >> 1;
          if (lcp(sB[mid], sA[i]) == k)
            r = (s = mid) - 1;
          else
            l = mid + 1;
        }
        sgt::modify(1, qm, 1, s, it - 1, k);
      }
      while (it <= qm && sA[i] >= sB[it]) {
        sgt::modify(1, qm, 1, it, it, lcp(sB[it], sA[i]));
        ++it;
      }
      ans += sgt::d[1];
    }
    sgt::build(1, qm, 1);
    for (int i = qn, it = qm; i; --i) {
      if (it != qm) {
        int k = lcp(sA[i], sB[it + 1]);
        int l = it + 1, r = qm, s = it + 1;
        while (l <= r) {
          const int mid = l + r >> 1;
          if (lcp(sA[i], sB[mid]) == k)
            r = (s = mid) - 1;
          else
            l = mid + 1;
        }
        sgt::modify(1, qm, 1, it + 1, s, k);
      }
      while (it && sA[i] < sB[it]) {
        sgt::modify(1, qm, 1, it, it, lcp(sA[i], sB[it]));
        --it;
      }
      ans += sgt::d[1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
