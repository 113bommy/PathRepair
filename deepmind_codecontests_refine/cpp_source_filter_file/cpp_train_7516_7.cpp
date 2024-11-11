#include <bits/stdc++.h>
using namespace std;
long long n, k;
const long long maxn = 55;
long long f[maxn], fac[maxn];
const long long inf = 1e18 + 1;
long long add(long long a, long long b) {
  if (a + b > inf)
    return inf;
  else
    return a + b;
}
long long mul(long long a, long long b) {
  if (inf / a < b)
    return inf;
  else
    return a * b;
}
long long ff(long long x) {
  if (x == 1)
    return 1;
  else
    return fac[x - 2];
}
long long y[101], x[101];
void pre() {
  fac[0] = 1;
  for (long long i = 1, iend = 50; i <= iend; ++i) fac[i] = mul(fac[i - 1], i);
  f[0] = 1;
  for (long long i = 1, iend = 50; i <= iend; ++i) {
    for (long long j = 1, jend = i; j <= jend; ++j) {
      f[i] = add(f[i], mul(ff(j), f[i - j]));
    }
  }
}
long long find(long long x) { return y[x] == 0 ? x : find(y[x]); }
long long vis[1010];
void h(long long n, long long k) {
  if (n == 1) {
    y[1] = 1;
    return;
  }
  for (long long i = 1, iend = n; i <= iend; ++i) vis[i] = 0, y[i] = 0;
  y[1] = n, vis[n] = 1;
  for (long long i = 2, iend = n - 1; i <= iend; ++i) {
    long long nw = fac[n - i - 1];
    for (long long j = 1, jend = n; j <= jend; ++j) {
      if (j != i && vis[j] == 0 && find(j) != i) {
        if (k <= nw) {
          y[i] = j;
          vis[j] = 1;
          break;
        }
        k -= nw;
      }
    }
  }
  for (long long i = 1, iend = n; i <= iend; ++i)
    if (!vis[i]) y[n] = i;
}
void g(long long n, long long k) {
  if (!n) return;
  long long l = 0;
  for (long long i = 1, iend = n; i <= iend; ++i) {
    long long nw = mul(ff(i), f[n - i]);
    if (k <= nw) {
      l = i;
      break;
    }
    k -= nw;
  }
  long long s1 = f[n - l];
  long long rnk = (k - 1) / s1 + 1;
  g(n - l, k - (rnk - 1) * rnk);
  for (long long i = n, iend = l + 1; i >= iend; --i) x[i] = x[i - l] + l;
  h(l, rnk);
  for (long long i = 1, iend = l; i <= iend; ++i) x[i] = y[i];
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pre();
  long long T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    if (f[n] < k) {
      cout << "-1" << endl;
      continue;
    }
    g(n, k);
    for (long long i = 1, iend = n; i <= iend; ++i) cout << x[i] << " ";
    cout << endl;
  }
}
