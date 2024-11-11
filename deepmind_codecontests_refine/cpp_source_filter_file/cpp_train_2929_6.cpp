#include <bits/stdc++.h>
using namespace std;
char buf[1 << 20], *p1, *p2;
template <class T>
inline void read(T &n) {
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
           ? 0
           : *p1++);
  T w = 1, x = 0;
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
             ? 0
             : *p1++);
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
             ? 0
             : *p1++);
  }
  n = x * w;
}
const int maxn = 50005;
const int maxm = 100000;
int n, a[maxn];
long long cnt[maxm + 5];
namespace wangdyakioi {
int Log[maxn], st[maxn][17];
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
void init() {
  for (int i = 1; i <= n; i++) st[i][0] = a[i];
  for (int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  for (int j = 1; j <= Log[n]; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
inline int ask(int l, int r) {
  int i = Log[r - l + 1];
  return gcd(st[l][i], st[r - (1 << i) + 1][i]);
}
void main() {
  init();
  for (int i = 1; i <= n; i++) {
    int L = i, now = a[i];
    while (L <= n) {
      int l = L, r = n, res = n;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (ask(i, mid) == now)
          res = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      cnt[now] += res - L + 1;
      L = res + 1, now = ask(i, L);
    }
  }
}
}  // namespace wangdyakioi
namespace orzwangdy {
long long f(long long a, long long b, long long c, long long n) {
  if (n < 0) return 0;
  if (!a) return b / c * (n + 1);
  if (a >= c || b >= c)
    return f(a % c, b % c, c, n) + a / c * n * (n + 1) / 2 + b / c + (n + 1);
  long long m = (a * n + b) / c;
  return m * n - f(c, c - b - 1, a, m - 1);
}
long long ask(long long a, long long b, long long c) {
  if (c < 0) return 0;
  return c / a + 1 + f(a, c % a, b, c / a);
}
long long getans(long long a, long long ca, long long b, long long cb,
                 long long c) {
  if (a * (ca - 1) + b * (cb - 1) <= c) return ca * cb;
  if (c < 0) return 0;
  return ask(a, b, c) - ask(a, b, c - ca * a) - ask(a, b, c - cb * b) +
         ask(a, b, c - ca * a - cb * b);
}
long long sumn[maxm + 5], sums[maxm + 5];
long long check(long long x) {
  long long res = 0;
  for (int i = 1; i <= maxm; i++) {
    if (!cnt[i]) continue;
    long long tmp = min(x / i, cnt[i]);
    res += cnt[i] * tmp - tmp * (tmp - 1) / 2;
  }
  for (int i = 1, j = 1; i < maxm; i++) {
    if (!cnt[i]) continue;
    if (i < j) res += cnt[i] * (sumn[j - 1] - sumn[i]);
    for (; j <= maxm && sums[j] - sums[i] <= x; j++)
      if (i != j && cnt[j])
        res += getans(i, cnt[i], j, cnt[j], x - sums[j - 1] + sums[i] - i - j);
    if (j <= maxm)
      if (i != j && cnt[j])
        res += getans(i, cnt[i], j, cnt[j], x - sums[j - 1] + sums[i] - i - j);
  }
  return res;
}
void main() {
  long long m = 1ll * n * (n + 1) / 2;
  m = m * (m + 1) / 2;
  m = (m + 1) / 2;
  for (int i = 1; i <= maxm; i++) {
    sumn[i] = sumn[i - 1] + cnt[i];
    sums[i] = sums[i - 1] + cnt[i] * i;
  }
  long long l = 1, r = sums[maxm], res = 1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid) >= m)
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << res << endl;
}
}  // namespace orzwangdy
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  wangdyakioi::main();
  orzwangdy::main();
  return 0;
}
