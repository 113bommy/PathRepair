#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x7fffffffffffffff;
__inline__ __attribute__((always_inline)) unsigned int rnd() {
  static unsigned int seed = 416;
  return seed ^= seed >> 5, seed ^= seed << 17, seed ^= seed >> 13;
}
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return (!b) ? a : gcd(b, a % b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp abs(const _Tp &a) {
  return a >= 0 ? a : -a;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp max(const _Tp &a, const _Tp &b) {
  return a < b ? b : a;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp min(const _Tp &a, const _Tp &b) {
  return a < b ? a : b;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmax(_Tp &a, const _Tp &b) {
  (a < b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmin(_Tp &a, const _Tp &b) {
  (b < a) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (ch < 48 || ch > 57) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (ch >= 48 && ch <= 57)
    x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
__inline__ __attribute__((always_inline)) int read_str(char *s) {
  char ch(getchar());
  while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
  char *tar = s;
  *tar = ch, ch = getchar();
  while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF)
    *(++tar) = ch, ch = getchar();
  return tar - s + 1;
}
const int N = 200005;
int sa[N], rnk[N], tax[N], tp[N];
int height[N];
int n, m;
void Rsort() {
  memset(tax, 0, (m + 3) << 2);
  for (int i = 1; i <= n; ++i) ++tax[rnk[i]];
  for (int i = 1; i <= m; ++i) tax[i] += tax[i - 1];
  for (int i = n; i >= 1; --i) sa[tax[rnk[tp[i]]]--] = tp[i];
}
void SA(char *s) {
  for (int i = 1; i <= n; ++i) rnk[i] = s[i], tp[i] = i;
  m = 127;
  Rsort();
  for (int w = 1, p = 1; p < n; w <<= 1, m = p) {
    p = 0;
    for (int i = 0; i < w; ++i) tp[++p] = n - i;
    for (int i = 1; i <= n; ++i)
      if (sa[i] > w) tp[++p] = sa[i] - w;
    Rsort();
    std::swap(rnk, tp);
    rnk[sa[1]] = p = 1;
    for (int i = 2; i <= n; ++i)
      rnk[sa[i]] =
          (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + w] == tp[sa[i] + w])
              ? p
              : ++p;
  }
  int k = 0;
  for (int i = 1; i <= n; ++i) {
    if (rnk[i] == 1) continue;
    if (k) --k;
    int j = sa[rnk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) ++k;
    height[rnk[i]] = k;
  }
}
char s[N];
int f[N][21], Log2[N];
__inline__ __attribute__((always_inline)) int Query(int l, int r) {
  int k = Log2[r - l + 1];
  return min(f[l][k], f[r - (1 << k) + 1][k]);
}
struct seg_tr {
  struct Node {
    int ls, rs;
    long long sum;
    bool tag;
  } f[N << 1];
  int node_cnt;
  __inline__ __attribute__((always_inline)) void PushUp(int x) {
    f[x].sum = f[f[x].ls].sum + f[f[x].rs].sum;
  }
  int build(int l, int r) {
    int cur = ++node_cnt;
    if (l == r) return cur;
    int mid = (l + r) >> 1;
    f[cur].ls = build(l, mid);
    f[cur].rs = build(mid + 1, r);
    return cur;
  }
  __inline__ __attribute__((always_inline)) void cover(int cur) {
    f[cur].sum = 0;
    f[cur].tag = 1;
  }
  __inline__ __attribute__((always_inline)) void PushDown(int cur) {
    if (f[cur].tag) {
      cover(f[cur].ls);
      cover(f[cur].rs);
      f[cur].tag = 0;
    }
  }
  void Update(int pos, int val, int cur = 1, int l = 0, int r = n) {
    if (l == r) {
      f[cur].sum += val;
      return;
    }
    PushDown(cur);
    int mid = (l + r) >> 1;
    if (pos <= mid)
      Update(pos, val, f[cur].ls, l, mid);
    else
      Update(pos, val, f[cur].rs, mid + 1, r);
    PushUp(cur);
  }
  void Modify(int L, int R, int cur = 1, int l = 0, int r = n) {
    if (L <= l && r <= R) {
      cover(cur);
      return;
    }
    PushDown(cur);
    int mid = (l + r) >> 1;
    if (L <= mid) Modify(L, R, f[cur].ls, l, mid);
    if (R > mid) Modify(L, R, f[cur].rs, mid + 1, r);
    PushUp(cur);
  }
  long long Query(int L, int R, int l = 0, int r = n, int cur = 1) {
    if (L <= l && r <= R) return f[cur].sum;
    PushDown(cur);
    int mid = (l + r) >> 1;
    return (L <= mid ? Query(L, R, l, mid, f[cur].ls) : 0) +
           (R > mid ? Query(L, R, mid + 1, r, f[cur].rs) : 0);
  }
} tr1, tr2;
long long solve(std::vector<int> v1, std::vector<int> v2) {
  tr1.Modify(1, n);
  tr2.Modify(1, n);
  std::vector<std::pair<int, int> > v;
  for (auto it : v1) v.push_back(std::make_pair(it, 1));
  for (auto it : v2) v.push_back(std::make_pair(it, 0));
  std::sort(v.begin(), v.end());
  std::reverse(v.begin(), v.end());
  int last = 0;
  long long ans = 0, sum = 0;
  for (auto it : v) {
    if (last) {
      int qwq = Query(it.first + 1, last);
      int cnt = tr1.Query(qwq, n);
      long long tot = tr2.Query(qwq, n);
      tr1.Modify(qwq, n);
      tr2.Modify(qwq, n);
      sum -= tot;
      sum += 1ll * cnt * qwq;
      tr1.Update(qwq, cnt);
      tr2.Update(qwq, 1ll * cnt * qwq);
    }
    if (it.second == 1) {
      ans += sum;
    } else {
      tr1.Update(height[it.first], 1);
      tr2.Update(height[it.first], height[it.first]);
      sum += height[it.first];
    }
    last = it.first;
  }
  v.clear();
  return ans;
}
int main() {
  int _;
  read(n, _);
  read_str(s + 1);
  SA(s);
  for (int i = 2; i <= n; ++i) Log2[i] = Log2[i >> 1] + 1;
  for (int i = n; i >= 1; --i) {
    f[i][0] = height[i];
    for (int j = 1; j <= 20 && i + (1 << (j - 1)) <= n; ++j) {
      f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
  tr1.build(0, n);
  tr2.build(0, n);
  while (_--) {
    int a, b;
    read(a, b);
    std::vector<int> v1, v2;
    int x;
    for (int i = 1; i <= a; ++i) {
      read(x);
      v1.push_back(rnk[x]);
    }
    for (int i = 1; i <= b; ++i) {
      read(x);
      v2.push_back(rnk[x]);
    }
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    long long ans = 0;
    for (auto it : v1) {
      auto itt = std::lower_bound(v2.begin(), v2.end(), it);
      if (itt != v2.end() && *itt == it) {
        ans += n - sa[it] + 1;
      }
    }
    printf("%lld\n", ans + solve(v1, v2) + solve(v2, v1));
  }
  return 0;
}
