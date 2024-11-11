#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int res;
long long n, ra, rb, rc, rd;
map<long long, string> mp;
inline int len(long long x, bool flag = false) {
  if (!x) return 1;
  int ret = 0;
  int tmp = inf;
  if (mp.count(x)) tmp = mp[x].size();
  while (x) {
    ++ret;
    x /= 10;
  }
  if (flag) return ret;
  return min(ret, tmp);
}
inline int getlen(long long a, long long b, long long c, long long d) {
  int ret = len(a, true);
  if (b != 1) ret += 1 + len(b);
  if (c != 1) ret += 1 + len(c);
  if (d != 0) ret += 1 + len(d);
  return ret;
}
inline void solve(long long a, long long b) {
  long long t = 1;
  for (int i = 0; i < b; ++i) t *= a;
  long long c = n / t;
  long long d = n - c * t;
  int len = getlen(a, b, c, d);
  if (len < res) res = len, ra = a, rb = b, rc = c, rd = d;
  d = n - t;
  len = getlen(a, b, 1, d);
  if (len < res) res = len, ra = a, rb = b, rc = 1, rd = d;
}
inline void print(long long x) {
  int l = len(x, true);
  if (!mp.count(x)) {
    printf("%I64d", x);
    return;
  }
  if ((int)mp[x].size() < l)
    cout << mp[x];
  else
    printf("%I64d", x);
}
inline void print(long long a, long long b, long long c, long long d) {
  printf("%I64d", a);
  if (b != 1) printf("^%I64d", b);
  if (c != 1) {
    putchar('*');
    print(c);
  }
  if (d != 0) {
    putchar('+');
    print(d);
  }
}
char tmp[105];
inline void update(char *s, long long v) {
  if (!mp.count(v) || mp[v].size() > string(s).size()) mp[v] = s;
}
int main() {
  cin >> n;
  for (long long i = 2; i * i <= n; ++i) {
    long long t = i;
    for (int j = 2;; ++j) {
      t *= i;
      if (t > n) break;
      sprintf(tmp, "%I64d^%d", i, j);
      update(tmp, t);
    }
  }
  res = len(n);
  ra = n, rb = 1, rc = 1, rd = 0;
  for (long long i = 2; i * i <= n; ++i) {
    long long t = 1;
    for (int j = 1;; ++j) {
      t *= i;
      if (t > n) break;
      solve(i, j);
    }
  }
  print(ra, rb, rc, rd);
  return 0;
}
