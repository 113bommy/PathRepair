#include <bits/stdc++.h>
using namespace std;
int n, a[100010];
long long k;
long long s[100010];
struct TAP {
  long long t[100010];
  void clear() { memset(t, 0, sizeof(long long) * (n + 1)); }
  void add(int x, long long c) {
    for (; x <= n; x += x & -x) t[x] += c;
  }
  long long query(int x) {
    long long r = 0;
    for (; x; x -= x & -x) r += t[x];
    return r;
  }
} cnt, sum;
struct TAMN {
  long long t[100010];
  void clear() { memset(t, 127, sizeof(long long) * (n + 1)); }
  void ins(int x, long long c) {
    for (; x <= n && c < t[x]; x += x & -x) t[x] = c;
  }
  long long query(int x) {
    long long r = LLONG_MAX;
    for (; x; x -= x & -x) r = min(r, t[x]);
    return r;
  }
} far;
int pre[100010], suc[100010];
int q[100010], re[100010];
long long val[100010];
bool cmpq(int x, int y) {
  return s[x - 1] < s[y - 1] || s[x - 1] == s[y - 1] && x < y;
}
int sep1[100010], sep2[100010];
long long mnl[100010];
long long ans;
long long judge(long long lim) {
  cnt.clear();
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    cnt.add(re[i], 1);
    long long x = upper_bound(val + 1, val + n + 1, s[i] - lim) - val - 1;
    res += cnt.query(x);
  }
  return res;
}
long long calc(long long lim, int *sep, bool need) {
  cnt.clear();
  if (need) sum.clear(), far.clear();
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    cnt.add(re[i], 1);
    if (need) sum.add(re[i], s[i - 1]), far.ins(re[i], i);
    long long x = upper_bound(val + 1, val + n + 1, s[i] - lim) - val - 1;
    int num = cnt.query(x);
    res += num;
    sep[i] = num;
    if (need) {
      ans += s[i] * num - sum.query(x), mnl[i] = far.query(x);
    }
  }
  return res;
}
void mend(long long lim, int *sep, bool need, long long rem) {
  cnt.clear();
  if (need) far.clear();
  for (int i = 1; i <= n && rem; ++i) {
    cnt.add(re[i], 1);
    if (need) far.ins(re[i], i);
    int x = upper_bound(val + 1, val + n + 1, s[i] - lim) - val - 1;
    int num = cnt.query(x);
    if (num - sep[i]) {
      int mn = min((long long)num - sep[i], rem);
      sep[i] += mn, rem -= mn;
      if (need) {
        ans += lim * mn;
        mnl[i] = far.query(x);
      }
    }
  }
}
void work(long long k, int *sep, bool need) {
  long long l = -5e9, r = 5e9, lim = 5e9;
  while (l <= r) {
    long long mid = l + r >> 1;
    long long tmp = judge(mid);
    if (tmp >= k)
      l = (lim = mid) + 1;
    else
      r = mid - 1;
  }
  long long rem = k - calc(lim + 1, sep, need);
  mend(lim, sep, need, rem);
}
struct Range {
  int l, r;
} ls[100010];
int m;
bool cmpls(Range x, Range y) {
  return s[x.r] - s[x.l - 1] > s[y.r] - s[y.l - 1];
}
void find() {
  q[0] = q[n + 1] = 0;
  for (int i = 1; i <= n; ++i) pre[q[i]] = q[i - 1], suc[q[i]] = q[i + 1];
  for (int i = n; i >= 1; --i) suc[pre[i]] = suc[i], pre[suc[i]] = pre[i];
  cnt.clear();
  for (int i = 1; i <= n; ++i) {
    suc[pre[i]] = i, pre[suc[i]] = i;
    cnt.add(re[i], 1);
    int l = 1, r = n, x = n;
    while (l <= r) {
      int mid = l + r >> 1;
      int tmp = cnt.query(mid);
      if (tmp >= sep2[i])
        r = (x = mid) - 1;
      else
        l = mid + 1;
    }
    x = q[x];
    for (int j = 0; j < sep2[i] - sep1[i]; ++j, x = pre[x]) ls[++m] = {x, i};
  }
  sort(ls + 1, ls + m + 1, cmpls);
}
struct Double_Heap {
  int k;
  multiset<long long> S, T;
  long long sumS;
  void insert(long long v) {
    if (S.empty()) {
      S.insert(v);
      sumS += v;
      return;
    }
    if (k == 0) {
      T.insert(v);
      return;
    }
    if (S.size() < k) {
      S.insert(v);
      sumS += v;
    } else {
      auto p = S.begin();
      if (v > *p) {
        long long u = *p;
        S.erase(p), T.insert(u);
        S.insert(v);
        sumS += v - u;
      } else
        T.insert(v);
    }
  }
  void erase(long long v) {
    if (S.empty()) {
      T.erase(v);
      return;
    }
    long long u = *S.begin();
    if (v >= u) {
      S.erase(S.find(v));
      sumS -= v;
      if (!T.empty()) {
        auto p = --T.end();
        long long w = *p;
        T.erase(p), S.insert(w);
        sumS += w;
      }
    } else
      T.erase(T.find(v));
  }
  void change(int _k) {
    for (; k > _k; --k) {
      if (S.size() < k) continue;
      auto p = S.begin();
      long long u = *p;
      S.erase(p), T.insert(u);
      sumS -= u;
    }
  }
  long long query() { return sumS; }
} dh;
struct RMQ {
  long long f[100010][17], g[100010][17];
  void init() {
    for (int i = 1; i <= n; ++i) {
      f[i][0] = s[i - 1];
      g[i][0] = s[i];
    }
    for (int i = 1; 1 << i <= n; ++i)
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        f[j][i] = min(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
        g[j][i] = max(g[j][i - 1], g[j + (1 << i - 1)][i - 1]);
      }
  }
  long long qmin(int l, int r) {
    int m = log2(r - l + 1);
    return min(f[l][m], f[r - (1 << m) + 1][m]);
  }
  long long qmax(int l, int r) {
    int m = log2(r - l + 1);
    return max(g[l][m], g[r - (1 << m) + 1][m]);
  }
} rmq;
inline bool operator<(Range x, Range y) {
  return x.l < y.l || x.l == y.l && x.r < y.r;
}
set<Range> ed;
long long getv(int l, int r) {
  return max(rmq.qmax(l, r) - s[l - 1], 0ll) + max(s[r] - rmq.qmin(l, r), 0ll) -
         (s[r] - s[l - 1]);
}
long long getlv(int r) {
  return (r < n ? max(s[r] - rmq.qmin(1, r), 0ll) - s[r] : 0);
}
long long getrv(int l) {
  return max(rmq.qmax(l, n) - s[l - 1], 0ll) - (s[n] - s[l - 1]);
}
int blocks;
void insert(int l, int r) {
  auto p = ed.lower_bound({l, 0}), q = p;
  if (p != ed.begin()) {
    --q;
    if (max(q->l, l) <= min(q->r, r) + 1) {
      l = min(q->l, l), r = max(q->r, r);
      if (q->l == 1)
        ans -= getlv(q->r);
      else if (q->r == n)
        ans -= getrv(q->l);
      else
        dh.erase(getv(q->l, q->r));
      blocks += q->r - q->l + 1;
      ed.erase(q);
    }
  }
  for (; p != ed.end() && max(p->l, l) <= min(p->r, r) + 1;) {
    l = min(p->l, l), r = max(p->r, r);
    q = p, p++;
    if (q->l == 1)
      ans -= getlv(q->r);
    else if (q->r == n)
      ans -= getrv(q->l);
    else
      dh.erase(getv(q->l, q->r));
    blocks += q->r - q->l + 1;
    ed.erase(q);
  }
  ed.insert({l, r});
  if (l == 1)
    ans += getlv(r);
  else if (r == n)
    ans += getrv(l);
  else
    dh.insert(getv(l, r));
  blocks -= r - l + 1;
}
int bz[100010];
void init() {
  blocks = n;
  for (int i = 1; i <= n; ++i) bz[mnl[i]]++, bz[i + 1]--;
  for (int i = 1; i <= n + 1; ++i) bz[i] += bz[i - 1];
  for (int i = 1, fir = 0; i <= n + 1; ++i)
    if (bool(bz[i]) != bool(bz[i - 1])) {
      if (bz[i])
        fir = i;
      else {
        insert(fir, i - 1);
        fir = i + 1;
      }
    }
}
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= n; ++i) q[i] = i;
  sort(q + 1, q + n + 1, cmpq);
  q[0] = 0, q[n + 1] = 0;
  for (int i = 1; i <= n; ++i) {
    val[i] = s[q[i] - 1];
    re[q[i]] = i;
  }
  memset(mnl, 127, sizeof(long long) * (n + 1));
  if (k > n) work(k - n, sep1, 1);
  for (int i = 1; i <= n; ++i) mnl[i] = min(mnl[i], i + 1ll);
  work(k, sep2, 0);
  find();
  rmq.init();
  dh.k = k - max(k - n, 0ll) - 1;
  init();
  long long res = -1e19;
  for (long long x = max(k - n, 0ll), i = 1; x < k; ++x, ++i) {
    if (k - x <= blocks) {
      dh.change(k - x - 1);
      res = max(res, ans + dh.query() + s[n]);
    }
    insert(ls[i].l, ls[i].r);
    ans += s[ls[i].r] - s[ls[i].l - 1];
  }
  if (ed.size() == 1 && ed.begin()->l == 1 && ed.begin()->r == n)
    res = max(res, ans);
  printf("%lld\n", res);
  return 0;
}
