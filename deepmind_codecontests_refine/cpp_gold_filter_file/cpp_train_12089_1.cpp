#include <bits/stdc++.h>
using namespace std;
const long long maxd = 1000000007, N = 300000;
const double pi = acos(-1.0);
long long n, q, a[200200], b[200200], numa, numb;
struct SA {
  long long n, sa[N + 100], rnk[N + 100], tp[N * 2 + 100], tax[N + 100], m,
      height[N + 100], low[N + 100], minq[N + 100][25];
  char s[N + 100];
  void qsort() {
    long long i;
    for (i = 0; i <= m; i++) tax[i] = 0;
    for (i = 1; i <= n; i++) tax[rnk[i]]++;
    for (i = 1; i <= m; i++) tax[i] += tax[i - 1];
    for (i = n; i >= 1; i--) sa[tax[rnk[tp[i]]]--] = tp[i];
  }
  void get_sa() {
    memset(rnk, 0, sizeof(rnk));
    memset(sa, 0, sizeof(sa));
    memset(tp, 0, sizeof(tp));
    memset(tax, 0, sizeof(tax));
    long long i, p = 0, w;
    n = strlen(s + 1);
    m = 30;
    for (i = 1; i <= n; i++) {
      rnk[i] = s[i] - 'a' + 1;
      tp[i] = i;
    }
    qsort();
    for (w = 1; p < n; w <<= 1) {
      p = 0;
      for (i = 1; i <= w; i++) tp[++p] = n - w + i;
      for (i = 1; i <= n; i++)
        if (sa[i] > w) tp[++p] = sa[i] - w;
      qsort();
      memcpy(tp, rnk, sizeof(tp));
      rnk[sa[1]] = 1;
      p = 1;
      for (i = 2; i <= n; i++)
        if ((tp[sa[i]] == tp[sa[i - 1]]) &&
            ((tp[sa[i] + w] == tp[sa[i - 1] + w])))
          rnk[sa[i]] = p;
        else
          rnk[sa[i]] = (++p);
      m = p;
    }
  }
  void get_h() {
    long long i, pre = 0;
    for (i = 1; i <= n; i++) {
      if (pre) pre--;
      long long j = sa[rnk[i] - 1];
      while ((i + pre <= n) && (j + pre <= n) && (s[i + pre] == s[j + pre]))
        pre++;
      height[rnk[i]] = pre;
    }
  }
  void init_st() {
    long long i, p;
    low[1] = 0;
    for (i = 2; i <= n; i++) low[i] = low[i >> 1] + 1;
    for (i = 1; i <= n; i++) minq[i][0] = height[i];
    for (p = 1; (1 << p) <= n; p++) {
      for (i = 1; i + (1 << p) - 1 <= n; i++) {
        minq[i][p] = min(minq[i][p - 1], minq[i + (1 << (p - 1))][p - 1]);
      }
    }
  }
  long long lcp(long long L, long long R) {
    if (L > R) swap(L, R);
    if (L == R) return n - sa[L] + 1;
    L++;
    long long p = low[R - L + 1];
    return min(minq[L][p], minq[R - (1 << p) + 1][p]);
  }
} sa;
struct segment_tree {
  long long cnt[(N << 2) + 100];
  long long sum[(N << 2) + 100];
  bool emp[(N << 2) + 100];
  void cls(long long id) {
    emp[id] = 1;
    cnt[id] = 0;
    sum[id] = 0;
  }
  void pushup(long long id) {
    cnt[id] = cnt[id << 1] + cnt[id << 1 | 1];
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
  }
  void pushdown(long long id) {
    if (emp[id]) {
      emp[id] = 0;
      cls(id << 1);
      cls(id << 1 | 1);
    }
  }
  void modify(long long id, long long l, long long r, long long val,
              long long tim) {
    if (!val) return;
    pushdown(id);
    if (l == r) {
      cnt[id] += tim;
      sum[id] += (1ll * val * tim);
      return;
    }
    long long mid = (l + r) >> 1;
    if (val <= mid)
      modify(id << 1, l, mid, val, tim);
    else
      modify(id << 1 | 1, mid + 1, r, val, tim);
    pushup(id);
  }
  long long clear(long long id, long long l, long long r, long long vall,
                  long long valr) {
    if (vall > valr) return 0;
    pushdown(id);
    if ((l == vall) && (r == valr)) {
      long long nowans = cnt[id];
      cls(id);
      return nowans;
    }
    long long mid = (l + r) >> 1, nowans;
    if (valr <= mid)
      nowans = clear(id << 1, l, mid, vall, valr);
    else if (vall > mid)
      nowans = clear(id << 1 | 1, mid + 1, r, vall, valr);
    else
      nowans = clear(id << 1, l, mid, vall, mid) +
               clear(id << 1 | 1, mid + 1, r, mid + 1, valr);
    pushup(id);
    return nowans;
  }
} seg;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
void init() {
  n = read();
  q = read();
  scanf("%s", sa.s + 1);
  sa.get_sa();
  sa.get_h();
  sa.init_st();
}
void work() {
  while (q--) {
    numa = read();
    numb = read();
    long long i, j;
    long long ans = 0;
    for (i = 1; i <= numa; i++) {
      long long tmp = read();
      a[i] = sa.rnk[tmp];
    }
    for (i = 1; i <= numb; i++) {
      long long tmp = read();
      b[i] = sa.rnk[tmp];
    }
    sort(a + 1, a + 1 + numa);
    sort(b + 1, b + 1 + numb);
    j = 1;
    for (i = 1; i <= numa; i++) {
      if (i == 1)
        seg.cls(1);
      else {
        long long lcp = sa.lcp(a[i - 1], a[i]);
        long long cnt = seg.clear(1, 1, n, lcp + 1, n);
        if (lcp) seg.modify(1, 1, n, lcp, cnt);
      }
      while ((j <= numb) && (b[j] <= a[i])) {
        long long lcp = sa.lcp(b[j], a[i]);
        seg.modify(1, 1, n, lcp, 1);
        j++;
      }
      ans += seg.sum[1];
    }
    j = 1;
    for (i = 1; i <= numb; i++) {
      if (i == 1)
        seg.cls(1);
      else {
        long long lcp = sa.lcp(b[i - 1], b[i]);
        long long cnt = seg.clear(1, 1, n, lcp + 1, n);
        if (lcp) seg.modify(1, 1, n, lcp, cnt);
      }
      while ((j <= numa) && (a[j] <= b[i])) {
        long long lcp = sa.lcp(a[j], b[i]);
        seg.modify(1, 1, n, lcp, 1);
        if (a[j] == b[i]) ans -= lcp;
        j++;
      }
      ans += seg.sum[1];
    }
    printf("%lld\n", ans);
  }
}
signed main() {
  init();
  work();
  return 0;
}
