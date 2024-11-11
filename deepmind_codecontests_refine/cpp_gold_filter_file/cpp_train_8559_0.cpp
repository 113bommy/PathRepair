#include <bits/stdc++.h>
char s[1005];
long long power[1005];
long long hash[1005];
const long long mod = 1e9 + 7, cc = 27;
long long getHash(int l, int r) {
  long long res = hash[r];
  long long minus = hash[l - 1] * power[r - l + 1];
  res = ((res - minus) % mod + mod) % mod;
  return res;
}
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }
int getPrefix(int u, int v, int n) {
  int l = 1, r = min(n - u + 1, n - v + 1);
  int res = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (getHash(u, u + m - 1) == getHash(v, v + m - 1)) {
      res = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  return res;
}
struct Element {
  int l, r;
  int n;
  std::string str;
  Element(int l = 0, int r = 0, int n = 0) : l(l), r(r), n(n) {}
  bool operator<(const Element &other) const { return str > other.str; }
};
Element a[1000005];
void preWork(int n) {
  hash[0] = 0;
  for (int i = 1; i <= n; i++) {
    long long u = s[i] - 'a' + 1;
    hash[i] = (hash[i - 1] * cc % mod + u) % mod;
  }
}
long long f[1005][1005];
long long sum[1005];
std::vector<int> end[1005];
long long quickNumber(int p, int n, int m) {
  long long upper = 1000000000000000000;
  int len = a[p].r - a[p].l + 1;
  for (int i = 1; i <= n; i++) end[i].clear();
  for (int i = 0; i <= m; i++) sum[i] = 0;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int cLen = min(len, getPrefix(i, a[p].l, n));
    if (cLen == len)
      end[i + cLen - 1].push_back(i);
    else
      end[i + cLen].push_back(i);
    for (unsigned int j = 0; j < end[i].size(); j++) {
      int u = end[i][j];
      if (s[i] >= s[a[p].l + i - u]) {
        for (int k = 0; k <= m; k++) {
          sum[k] += f[u - 1][k];
          if (sum[k] >= upper) sum[k] = upper;
        }
      }
    }
    for (int j = m; j >= 1; j--) {
      f[i][j] = 0;
      if (j > i) continue;
      f[i][j] = sum[j - 1];
      if (f[i][j] >= upper) f[i][j] = upper;
    }
  }
  return f[n][m];
}
long long d[1005][1005];
int isBigger(int a, int b, int c, int d) {
  int len0 = b - a + 1, len1 = d - c + 1;
  for (int i = 0; i < max(len0, len1); i++) {
    if (i < len0 && i < len1) {
      if (s[a + i] != s[c + i]) return s[a + i] > s[c + i];
    } else if (i < len0)
      return 1;
    else
      return 0;
  }
  return 0;
}
long long getNumber(int p, int n, int m) {
  int l = a[p].l, r = a[p].r;
  d[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[i][j] = 0;
      for (int k = i - 1; k >= 0; k--) {
        if (!isBigger(l, r, k + 1, i)) d[i][j] += d[k][j - 1];
      }
      if (d[i][j]) printf("d[%d][%d] = %lld\n", i, j, d[i][j]);
    }
  }
  printf("%lld\n", d[n][m]);
  return d[n][m];
}
int main() {
  power[0] = 1;
  for (int i = 1; i <= 1000; i++) power[i] = power[i - 1] * cc % mod;
  int n, m;
  long long k;
  scanf("%d%d%lld%s", &n, &m, &k, s + 1);
  preWork(n);
  int total = 0;
  std::set<Element> order;
  for (int i = 1; i <= n; i++) {
    std::string u = "";
    for (int j = i; j <= n; j++) {
      u = u + s[j];
      a[++total] = Element(i, j, n);
      a[total].str = u;
      order.insert(a[total]);
    }
  }
  int now = 0;
  auto it = order.begin();
  while (it != order.end()) {
    now++;
    a[now].l = (*it).l;
    a[now].r = (*it).r;
    it++;
  }
  int L = 1, R = now;
  int ans = -1;
  while (L <= R) {
    int M = (L + R) / 2;
    if (quickNumber(M, n, m) >= k) {
      ans = M;
      R = M - 1;
    } else
      L = M + 1;
  }
  for (int i = a[ans].l; i <= a[ans].r; i++) printf("%c", s[i]);
  printf("\n");
  return 0;
}
