#include <bits/stdc++.h>
const int N = 2e5 + 10, M = 26;
int n;
char str[N];
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
struct sa {
  int sa[N], a[N], b[N], buc[N], h[N], f[N][20], Log[N];
  inline void sort(int *a, int *b, int n, int m) {
    for (int i = 1; i <= m; ++i) buc[i] = 0;
    for (int i = 1; i <= n; ++i) buc[a[i]] = buc[a[i]] + 1;
    for (int i = 1; i <= m; ++i) buc[i] += buc[i - 1];
    for (int i = n; i >= 1; --i) sa[buc[a[b[i]]]--] = b[i];
  }
  inline int cmp(int *f, int a, int b, int k) {
    return f[a] == f[b] && f[a + k] == f[b + k];
  }
  inline void build(char *s) {
    int n = strlen(s + 1), m = 0;
    for (int i = 1; i <= n; ++i) m = std::max(m, a[i] = s[i]), b[i] = i;
    sort(a, b, n, m);
    for (int p = 0, j = 1; p < n; j <<= 1, m = p) {
      p = 0;
      for (int i = 1; i <= j; ++i) b[++p] = n - i + 1;
      for (int i = 1; i <= n; ++i)
        if (sa[i] > j) b[++p] = sa[i] - j;
      sort(a, b, n, m), std::swap(a, b), a[sa[1]] = p = 1;
      for (int i = 2; i <= n; ++i)
        a[sa[i]] = cmp(b, sa[i], sa[i - 1], j) ? p : ++p;
    }
    for (int i = 1, k = 0; i <= n; ++i) {
      if (k) --k;
      while (s[i + k] == s[sa[a[i] - 1] + k]) ++k;
      h[a[i]] = k;
    }
    Log[0] = -1;
    for (int i = 1; i <= n; ++i) f[i][0] = h[i], Log[i] = Log[i >> 1] + 1;
    for (int w = 1; w < 20; ++w)
      for (int i = 1; i + (1 << w) - 1 <= n; ++i)
        f[i][w] = std::min(f[i][w - 1], f[i + (1 << w - 1)][w - 1]);
  }
  inline int ask(int l, int r) {
    int x = std::min(a[l], a[r]) + 1, y = std::max(a[l], a[r]),
        w = Log[y - x + 1];
    return std::min(f[x][w], f[y - (1 << w) + 1][w]);
  }
} A, B;
int l[N], r[N], Log[N], f[N][20];
std::vector<int> L_add[N], L_del[N];
std::vector<int> R_add[N], R_del[N];
inline int ask(int l, int r) {
  int w = Log[r - l + 1];
  return std::min(f[l][w], f[r - (1 << w) + 1][w]);
}
int cnt[N][M];
std::vector<int> fac[N];
inline int solve(int L, int R) {
  int flg = 0;
  for (int i = 0; i < M; ++i) flg |= cnt[R][i] - cnt[L - 1][i] > 1;
  if (flg == 0) return -1;
  int LEN = R - L + 1, B = sqrt(n);
  for (auto len : fac[LEN])
    if (A.ask(L, L + LEN / len) >= LEN - LEN / len) return 1;
  if (r[L] <= R || l[R] >= L) return 2;
  for (int i = 1; i <= std::min(B, LEN); ++i)
    if (A.ask(L, R - i + 1) >= i) return 2;
  int border = n + 1;
  for (int i = std::max(1, A.a[L] - B); i <= std::min(n, A.a[L] + B); ++i)
    if (L < A.sa[i] && A.sa[i] <= R && A.ask(L, A.sa[i]) >= R - A.sa[i] + 1)
      border = std::min(border, R - A.sa[i] + 1);
  if (2 * border <= R - L + 1) return 2;
  if (cnt[R][str[L] - 'a'] - cnt[L][str[L] - 'a']) return 3;
  if (cnt[R - 1][str[R] - 'a'] - cnt[L - 1][str[R] - 'a']) return 3;
  if (ask(L, R) < R) return 3;
  return 4;
}
int main() {
  n = read();
  for (int i = 2; i <= n; ++i)
    if (fac[i].empty())
      for (int j = i; j <= n; j += i) fac[j].push_back(i);
  scanf("%s", str + 1);
  A.build(str), std::reverse(str + 1, str + n + 1);
  B.build(str), std::reverse(str + 1, str + n + 1);
  for (int len = 1; len <= n / 2; ++len)
    for (int i = len, j = len * 2; j <= n; i += len, j += len) {
      int x = std::min(B.ask(n - i + 1, n - j + 1), len);
      int y = std::min(A.ask(i + 1, j + 1), len - 1);
      int t = x + y - len + 1;
      if (t > 0) {
        R_add[i - x + 1].push_back(len);
        R_del[i - x + t + 1].push_back(len);
        L_add[j + y - t + 1].push_back(len);
        L_del[j + y + 1].push_back(len);
      }
    }
  std::set<int> L;
  for (int i = 1; i <= n; ++i) {
    for (auto len : L_del[i]) L.erase(len);
    for (auto len : L_add[i]) L.insert(len);
    l[i] = L.empty() ? 0 : i - 2 * *L.begin() + 1;
  }
  std::set<int> R;
  for (int i = 1; i <= n; ++i) {
    for (auto len : R_del[i]) R.erase(len);
    for (auto len : R_add[i]) R.insert(len);
    r[i] = R.empty() ? n + 1 : i + 2 * *R.begin() - 1;
  }
  for (int i = 1; i <= n; ++i) {
    memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i]));
    cnt[i][str[i] - 'a'] += 1;
  }
  Log[0] = -1;
  for (int i = 1; i <= n; ++i) f[i][0] = r[i], Log[i] = Log[i >> 1] + 1;
  for (int w = 1; w < 20; ++w)
    for (int i = 1; i + (1 << w) - 1 <= n; ++i)
      f[i][w] = std::min(f[i][w - 1], f[i + (1 << w - 1)][w - 1]);
  for (int q = read(); q; --q) {
    int L = read(), R = read();
    printf("%d\n", solve(L, R));
  }
  return 0;
}
