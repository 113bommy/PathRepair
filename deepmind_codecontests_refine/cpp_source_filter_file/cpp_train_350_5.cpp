#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000,1000000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
long long n, m, ans = 0;
long long a[1000005], b[1000005];
vector<long long> t[4000005];
inline long long f(long long x) {
  long long res = x + ans - 1;
  if (res < 0) res += n;
  if (res >= n) res -= n;
  return res;
}
inline void build(long long v, long long l, long long r) {
  if (l == r) {
    t[v].push_back(a[l]);
    return;
  }
  long long m = (l + r) >> 1LL;
  if (l <= m) build(v + v, l, m);
  if (r > m) build(v + v + 1, m + 1, r);
  merge(t[v + v].begin(), t[v + v].end(), t[v + v + 1].begin(),
        t[v + v + 1].end(), back_inserter(t[v]));
}
inline long long get(long long v, long long tl, long long tr, long long a,
                     long long b, long long c, long long d) {
  if (a <= tl && b >= tr) {
    return upper_bound((t[v]).begin(), (t[v]).end(), d) -
           lower_bound((t[v]).begin(), (t[v]).end(), c);
  }
  long long tm = (tl + tr) >> 1LL;
  long long res = 0;
  if (a <= tm) res += get(v + v, tl, tm, a, b, c, d);
  if (b > tm) res += get(v + v + 1, tm + 1, tr, a, b, c, d);
  return res;
}
int main(void) {
  cin >> n;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    int x;
    scanf("%d", &x);
    b[x - 1] = i;
  }
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    int x;
    scanf("%d", &x);
    a[i] = b[x - 1];
  }
  build(1, 0, n - 1);
  cin >> m;
  for (long long(i) = 0; (i) < (long long)(m); (i)++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a = f(a);
    b = f(b);
    c = f(c);
    d = f(d);
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    ans = get(1, 0, n - 1, c, d, a, b);
    printf("%d\n", (int)ans);
    ans++;
  }
  return 0;
}
