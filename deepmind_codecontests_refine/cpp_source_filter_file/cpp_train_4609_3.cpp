#include <bits/stdc++.h>
const int lim = 1e6 + 7;
const int mod = 1e9 + 7;
int b1 = 23;
int b2 = 29;
int m1 = 1e9 + 7;
int m2 = 998244353;
std::vector<int> A[1000005], RNK[1000005], dp[1000005], h1[1000005],
    h2[1000005];
int pw1[lim + 7], pw2[lim + 7], L[1000005], n, ans, ipw1[lim + 7],
    ipw2[lim + 7];
char s[lim + 7];
int qpow(int a, int b, int m) {
  if (b == 0) return 1;
  long long d = qpow(a, b >> 1, m);
  d = d * d % m;
  if (b & 1) d = d * a % m;
  return d;
}
int dec(int x, int y) { return x >= y ? x - y : x; }
void work(int x) {
  std::vector<int> s;
  for (int y : A[x]) s.push_back(y);
  std::vector<int> r, a, l;
  int n = L[x], t = 0;
  r.resize(n + 2);
  l.resize(n + 2);
  a.resize(n + 2);
  RNK[x].resize(n + 2);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == s[i - 1])
      r[t] = i;
    else
      a[++t] = s[i], l[t] = r[t] = i;
  }
  int p1 = 1, p2 = n;
  for (int i = 1; i < t; ++i) {
    if (a[i] < a[i + 1])
      for (int j = r[i]; j >= l[i]; --j) RNK[x][p2--] = j;
    if (a[i] > a[i + 1])
      for (int j = l[i]; j <= r[i]; ++j) RNK[x][p1++] = j;
  }
  for (int i = 1; i <= n; ++i)
    if (!RNK[x][i]) RNK[x][i] = l[t]++;
}
void print(std::pair<int, int> p) { printf("(%d %d)\n", p.first, p.second); }
std::pair<int, int> hasher(int x, int l, int r) {
  if (r == 0 || l > r) return std::make_pair(0, 0);
  return std::make_pair(
      dec(h1[x][r] - (long long)h1[x][l - 1] * pw1[r - l + 1] % m1 + m1, m1),
      0);
}
std::pair<int, int> hasher_merge(std::pair<int, int> l, std::pair<int, int> r,
                                 int rlen) {
  return std::make_pair(dec((long long)l.first * pw1[rlen] % m1 + r.first, m1),
                        0);
}
std::pair<int, int> hasher_pre(int x, int len, int d) {
  if (len < d)
    return hasher(x, 1, len);
  else {
    return hasher_merge(hasher(x, 1, d - 1), hasher(x, d + 1, len + 1),
                        (len + 1 - (d + 1) + 1));
  }
}
int get(int x, int i, int d) {
  if (i >= L[x]) return 0;
  if (i < d) return A[x][i];
  return A[x][i + 1];
}
int check(int x1, int d1, int x2, int d2) {
  if (std::min(L[x1], L[x2]) <= 20) {
    for (int i = 1; i; ++i) {
      int a1 = get(x1, i, d1), a2 = get(x2, i, d2);
      if (a1 != a2) return a1 < a2;
      if (a1 == a2 && a2 == 0) return 1;
    }
  }
  int l = 1, r = std::min(L[x1], L[x2]) - 1, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (hasher_pre(x1, mid, d1) == hasher_pre(x2, mid, d2)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return get(x1, ans + 1, d1) <= get(x2, ans + 1, d2);
}
int main() {
  scanf("%d", &n);
  pw1[0] = ipw1[0] = pw2[0] = ipw2[0] = 1;
  for (int i = 1; i <= lim; ++i) {
    pw1[i] = (long long)pw1[i - 1] * b1 % m1;
    pw2[i] = (long long)pw2[i - 1] * b2 % m2;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    int len = std::strlen(s + 1);
    s[++len] = 'a' - 1;
    L[i] = len;
    A[i].resize(len + 3);
    h1[i].resize(len + 3);
    h2[i].resize(len + 3);
    for (int j = 1; j <= len; ++j) {
      A[i][j] = s[j] - 'a' + 1;
      h1[i][j] = ((long long)h1[i][j - 1] * b1 + A[i][j]) % m1;
      h2[i][j] = ((long long)h2[i][j - 1] * b2 + A[i][j]) % m2;
    }
    work(i);
  }
  dp[1].resize(L[1] + 2);
  for (int i = 1; i <= L[1]; ++i) dp[1][i] = i;
  for (int i = 2; i <= n; ++i) {
    dp[i].resize(L[i] + 2);
    int p = 0;
    for (int j = 1; j <= L[i]; ++j) {
      int cur = RNK[i][j];
      while (p < L[i - 1]) {
        if (check(i - 1, RNK[i - 1][p + 1], i, cur))
          p++;
        else
          break;
      }
      dp[i][j] = dp[i - 1][p];
    }
    for (int j = 1; j <= L[i]; ++j) dp[i][j] = (dp[i][j - 1] + dp[i][j]) % mod;
  }
  printf("%d", dp[n][L[n]]);
  return 0;
}
