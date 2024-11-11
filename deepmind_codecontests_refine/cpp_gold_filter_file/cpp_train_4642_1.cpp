#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, m, r, x, y, K, tot, sz, cur, sum, n, c, maxlvl, q,
    start_pnt;
string s, t;
long long prime[200500], used[200500], dp[200500];
vector<long long> f;
double p;
long long binpow(long long x, long long y, long long md) {
  if (y == 0) return 1 % md;
  long long tmp = binpow(x, y / 2, md);
  tmp = (tmp * tmp) % md;
  if (y % 2 == 0) return tmp;
  return (x * tmp) % md;
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
int gcdex(int a, int b, int& x, int& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int fldgjdflgjhrthrl, fldggfhfghjdflgjl;
  int d = gcdex(b % a, a, fldgjdflgjhrthrl, fldggfhfghjdflgjl);
  x = fldggfhfghjdflgjl - (b / a) * fldgjdflgjhrthrl;
  y = fldgjdflgjhrthrl;
  return d;
}
int main() {
  for (i = 2; i <= 200000; i++) {
    prime[i] = 1;
  }
  for (i = 2; i <= 200000; i++)
    if (prime[i])
      for (j = i * 2; j <= 200000; j += i) prime[j] = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> x;
    used[x] = 1;
  }
  long long lst;
  if (prime[m]) {
    for (i = 1; i <= m - 1; i++) {
      if (!used[i]) {
        if (f.size() == 0) {
          f.push_back(i);
          lst = i;
        } else {
          x = (i * binpow(lst, m - 2, m)) % m;
          f.push_back(x);
          lst = i;
        }
      }
    }
    if (!used[0]) f.push_back(0);
    cout << f.size() << endl;
    for (i = 0; i < f.size(); i++) cout << f[i] << " ";
    return 0;
  }
  long long ans = -1, idx;
  for (i = 1; i <= m - 1; i++)
    if (prime[i] && m % i == 0) {
      long long cnt = 0;
      for (j = i; j <= m - 1; j += i)
        if (!used[j]) cnt++;
      if (cnt > ans) {
        ans = cnt;
        idx = i;
      }
    }
  for (i = 2; i <= m; i++)
    if (m % i == 0) {
      long long v = m / i;
      long long tmp = 0;
      for (j = v; j <= m - 1; j += v) {
        long long g = gcd(j / v, i);
        if (g == 1)
          dp[i] += 1 - used[j];
        else
          tmp = max(tmp, dp[i / g]);
      }
      dp[i] += tmp;
    }
  long long x = m;
  long long next_rev = -1, last_v, last_md;
  while (x != 1) {
    long long v = m / x;
    for (j = 1; j <= x - 1; j++)
      if (!used[j * v] && gcd(j, x) == 1) {
        if (next_rev == -1) {
          f.push_back(j * v);
          int vv = j;
          int xx, y;
          int g = gcdex(vv, x, xx, y);
          xx = (xx % x + x) % x;
          last_v = v;
          last_md = x;
          next_rev = xx;
        } else {
          next_rev = (j * v / last_v * next_rev) % last_md;
          f.push_back(next_rev);
          int vv = j;
          int xx, y;
          int g = gcdex(vv, x, xx, y);
          xx = (xx % x + x) % x;
          last_v = v;
          last_md = x;
          next_rev = xx;
        }
      }
    long long ans = -1, idx;
    for (j = 1; j <= x - 1; j++)
      if (x % j == 0) {
        if (dp[j] > ans) ans = dp[j], idx = j;
      }
    x = idx;
  }
  if (!used[0]) f.push_back(0);
  cout << f.size() << endl;
  for (i = 0; i < f.size(); i++) cout << f[i] << " ";
  return 0;
}
