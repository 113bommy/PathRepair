#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int tl[N * 4], tr[N * 4], p[N * 4], L[N], R[N], n, Q, o, f[N][26], b[N];
char s[N], t[N];
vector<int> a[N];
struct SA {
  int c[N], x[N], y[N], sa[N], m, height[N], h[N][20], rk[N];
  void get_sa(char *s, int n) {
    register int cnt = 0;
    for (int i = (0); i <= (m); ++i) c[i] = 0;
    for (int i = (1); i <= (n); ++i) c[x[i] = s[i]]++;
    for (int i = (1); i <= (m); ++i) c[i] += c[i - 1];
    for (int i = (n); i >= (1); --i) sa[c[x[i]]--] = i;
    for (register int k = 1; k <= n; k <<= 1) {
      cnt = 0;
      for (int i = (n - k + 1); i <= (n); ++i) y[++cnt] = i;
      for (int i = (1); i <= (n); ++i)
        if (sa[i] > k) y[++cnt] = sa[i] - k;
      for (int i = (1); i <= (m); ++i) c[i] = 0;
      for (int i = (1); i <= (n); ++i) ++c[x[i]];
      for (int i = (1); i <= (m); ++i) c[i] += c[i - 1];
      for (int i = (n); i >= (1); --i) sa[c[x[y[i]]]--] = y[i];
      swap(x, y);
      x[sa[1]] = cnt = 1;
      for (int i = (2); i <= (n); ++i)
        x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && sa[i] + k <= n &&
                    sa[i - 1] + k <= n && y[sa[i] + k] == y[sa[i - 1] + k])
                       ? cnt
                       : ++cnt;
      if (cnt == n) break;
      m = cnt;
    }
  }
  void get_height(char *s, int n) {
    register int k = 0;
    for (int i = (1); i <= (n); ++i) rk[sa[i]] = i;
    for (int i = (1); i <= (n); ++i) {
      if (rk[i] == 1) continue;
      if (k) --k;
      int j = sa[rk[i] - 1];
      while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) ++k;
      height[rk[i]] = k;
    }
  }
  void build_st(int n) {
    for (int i = (1); i <= (n); ++i) h[i][0] = height[i];
    for (int i = (1); i <= (18); ++i)
      for (int j = (1); j <= (n - (1 << i) + 1); ++j)
        h[j][i] = min(h[j][i - 1], h[j + (1 << i - 1)][i - 1]);
  }
  void build(char *s, int n) {
    m = 127;
    get_sa(s, n);
    get_height(s, n);
    build_st(n);
  }
  int lcp(int x, int y) {
    int l = rk[x], r = rk[y];
    if (l > r) swap(l, r);
    ++l;
    int t = b[r - l + 1];
    return min(h[l][t], h[r - (1 << t) + 1][t]);
  }
} S, T;
bool check(int l, int r) {
  for (int i = (0); i <= (25); ++i)
    if (f[r][i] - f[l - 1][i] > 1) return 0;
  return 1;
}
bool pd(int l, int r) {
  int len = r - l + 1;
  for (int &x : a[len])
    if (S.lcp(l, l + x) >= len - x) return 1;
  return 0;
}
int border(int l, int r) {
  for (int i = (1); i <= (o); ++i)
    if (S.lcp(l, r - i + 1) >= i) return i;
  int ans = n, tl = max(1, S.rk[l] - o), tr = min(n, S.rk[l] + o);
  for (int i = (tl); i <= (tr); ++i)
    if (S.sa[i] <= r && S.lcp(S.sa[i], l) >= r - S.sa[i] + 1)
      ans = min(ans, r - S.sa[i] + 1);
  return ans;
}
void updl(int l, int r, int o, int ql, int qr, int x) {
  if (ql > r || qr < l) return;
  if (ql <= l && r <= qr) {
    tl[o] = x;
    return;
  }
  int mid = (l + r) >> 1;
  updl(l, mid, o << 1, ql, qr, x);
  updl(mid + 1, r, o << 1 | 1, ql, qr, x);
}
void updr(int l, int r, int o, int ql, int qr, int x) {
  if (ql > r || qr < l) return;
  if (ql <= l && r <= qr) {
    tr[o] = x;
    return;
  }
  int mid = (l + r) >> 1;
  updr(l, mid, o << 1, ql, qr, x);
  updr(mid + 1, r, o << 1 | 1, ql, qr, x);
}
inline void pd(int o) {
  tl[o << 1] = min(tl[o << 1], tl[o]);
  tr[o << 1] = min(tr[o << 1], tr[o]);
  tl[o << 1 | 1] = min(tl[o << 1 | 1], tl[o]);
  tr[o << 1 | 1] = min(tr[o << 1 | 1], tr[o]);
}
void down(int o, int l, int r) {
  if (l == r) {
    R[l] = tr[o] * 2 + l - 1;
    L[l] = r - tl[o] * 2 + 1;
    p[o] = R[l];
    return;
  }
  pd(o);
  int mid = (l + r) >> 1;
  down(o << 1, l, mid);
  down(o << 1 | 1, mid + 1, r);
  p[o] = min(p[o << 1], p[o << 1 | 1]);
}
int que(int o, int l, int r, int ql, int qr) {
  if (ql > r || qr < l) return n + 1;
  if (ql <= l && r <= qr) return p[o];
  int mid = (l + r) >> 1;
  return min(que(o << 1, l, mid, ql, qr), que(o << 1 | 1, mid + 1, r, ql, qr));
}
void solve() {
  for (int i = (n / 2); i >= (1); --i)
    for (int j = (i); j <= (n - i); j += i) {
      int k = i + j, l1 = min(i, S.lcp(j, k)),
          l2 = min(i - 1, T.lcp(n - j + 2, n - k + 2));
      if (l1 + l2 < i) continue;
      int t = l1 + l2 - i + 1;
      updr(1, n, 1, j - l2, j - l2 + t - 1, i);
      updl(1, n, 1, k + l1 - t, k + l1 - 1, i);
    }
  down(1, 1, n);
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = (1); i <= (n); ++i) t[n - i + 1] = s[i];
  for (int i = (1); i <= (n * 4); ++i) tl[i] = tr[i] = n + 1;
  for (int i = (2); i <= (n); ++i) b[i] = b[i >> 1] + 1;
  o = (int)sqrt(n + 0.5) + 1;
  for (int i = (1); i <= (n); ++i)
    for (int j = (2); j <= (n / i); ++j) a[i * j].push_back(i);
  for (int i = (1); i <= (n); ++i) {
    for (int j = (0); j <= (25); ++j) f[i][j] = f[i - 1][j];
    f[i][s[i] - 'a']++;
  }
  S.build(s, n);
  T.build(t, n);
  solve();
  scanf("%d", &Q);
  while (Q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int x = s[l] - 'a', y = s[r] - 'a';
    if (r - l + 1 <= 26 && check(l, r)) {
      puts("-1");
      continue;
    }
    if (pd(l, r))
      puts("1");
    else if (R[l] <= r || L[r] >= l || border(l, r) <= (r - l + 1) / 2)
      puts("2");
    else if (f[r][x] - f[l - 1][x] > 1 || f[r][y] - f[l - 1][y] > 1 ||
             que(1, 1, n, l, r) <= r)
      puts("3");
    else
      puts("4");
  }
  return 0;
}
