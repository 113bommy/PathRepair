#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long n, long long k, int p = (int)1e9 + 7) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = 2 * acos((long double)0);
const int maxn = 1000010;
const int maxq = 60;
const int maxe = 20;
int n, q;
int a[maxn << 1];
long long b[maxn];
long long sum[maxn << 1];
int nxt[maxn << 1];
long long calc(int l, int r) {
  if (!l) return sum[r];
  return sum[r] - sum[l - 1];
}
void solve() {
  scanf("%d%d", &n, &q);
  for (int i = (0); i < (n); i++) {
    scanf("%d", a + i);
    a[i + n] = a[i];
  }
  for (int i = (0); i < (q); i++) scanf("%I64d", b + i);
  for (int i = (0); i < (n << 1); i++) {
    if (!i)
      sum[i] = a[i];
    else
      sum[i] = sum[i - 1] + a[i];
  }
  for (int k = (0); k < (q); k++) {
    int cur = 0;
    for (int i = (0); i < (n << 1); i++) {
      while (cur < i || cur < (n << 1) - 1 && calc(i, cur + 1) <= b[k]) cur++;
      nxt[i] = cur + 1;
    }
    int idx = 0, dmin = INF;
    for (int i = (0); i < (n); i++) {
      if (dmin > nxt[i] - i) {
        dmin = nxt[i] - i;
        idx = i;
      }
    }
    int res = INF;
    for (int i = (idx); i < (min(n, nxt[idx] + 1)); i++) {
      int cur = i, tot = 0;
      while (cur < min(n << 1, i + n)) {
        cur = nxt[cur];
        tot++;
      }
      res = min(res, tot);
    }
    printf("%d\n", res);
  }
}
int main() {
  solve();
  return 0;
}
