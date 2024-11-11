#include <bits/stdc++.h>
using std::cerr;
using std::endl;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int MAXN = 1000005;
int n, cnt, mp2[(1 << 11) + 5];
long long K, d, p[MAXN], q[MAXN][12];
long long f[12][(1 << 11) + 5];
bool valid[MAXN];
std::vector<int> vec[MAXN];
std::map<long long, int> mp;
struct info {
  long long num;
  int w;
  inline friend bool operator<(info x, info y) { return x.w < y.w; }
} a[MAXN];
inline long long gcd(long long x, long long y) {
  if (!x || !y) return x + y;
  while (y) {
    std::swap(x, y);
    y %= x;
  }
  return x;
}
int main() {
  n = read(), K = read();
  for (int i = (1); i <= (n); ++i) d = gcd(d, a[i].num = read());
  for (int i = (1); i <= (n); ++i) a[i].w = read();
  std::sort(a + 1, a + n + 1);
  int lim = sqrt((long double)d) + 0.5;
  for (int i = (2); i <= (lim); ++i) {
    if (d % i) continue;
    while (d % i == 0) d /= i;
    p[++cnt] = i;
  }
  if (d > 1) p[++cnt] = d;
  if (!cnt) {
    printf("0\n");
    return 0;
  }
  for (int i = (1); i <= (n); ++i) {
    long long temp = 1;
    for (int j = (1); j <= (cnt); ++j) {
      long long temp2 = 1;
      while (a[i].num % p[j] == 0) {
        a[i].num /= p[j];
        temp *= p[j];
        temp2 *= p[j];
      }
      q[i][j] = temp2;
    }
    if (mp[temp] < cnt) {
      ++mp[temp];
      valid[i] = true;
      for (int s = (0); s <= ((1 << cnt) - 1); ++s) {
        long long temp2 = 1;
        for (int j = (1); j <= (cnt); ++j)
          if ((s >> (j - 1)) & 1) temp2 *= q[i][j];
        if (temp2 <= K && mp2[s] < cnt) {
          ++mp2[s];
          vec[i].push_back(s);
        }
      }
    }
  }
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  for (int i = (1); i <= (n); ++i) {
    if (!valid[i]) continue;
    for (int j = (cnt); j >= (1); --j) {
      for (auto t : vec[i]) {
        for (int s = t;; s = ((s + 1) | t)) {
          f[j][s] = std::min(f[j][s], f[j - 1][s ^ t] + a[i].w);
          if (s == (1 << cnt) - 1) break;
        }
      }
    }
  }
  long long ans = 1e18;
  for (int i = (1); i <= (cnt); ++i)
    if (f[i][(1 << cnt) - 1] < 1e18)
      ans = std::min(ans, i * f[i][(1 << cnt) - 1]);
  printf("%I64d\n", ans < 1e18 ? ans : -1);
  return 0;
}
