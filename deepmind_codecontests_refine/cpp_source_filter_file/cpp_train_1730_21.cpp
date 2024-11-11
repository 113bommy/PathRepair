#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1000000;
const double pi = 3.1415926535897932384626433832795;
using namespace std;
long long pref[7000000];
long long sum[7000000];
bool p[7000000];
long long st[300000];
long long x1[300000];
long long h1 = 0;
long long col(long long l, long long r) { return pref[r] - pref[l - 1]; }
long long getsum(long long l, long long r) { return sum[r] - sum[l - 1]; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  srand(time(0));
  long long n, x, y;
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> x1[i];
    pref[x1[i]]++;
    sum[x1[i]] += x1[i];
  }
  for (int i = 1; i <= 1000000; i++) pref[i] += pref[i - 1];
  for (int i = 1; i <= 1000000; i++) sum[i] += sum[i - 1];
  for (long long i = 2; i <= 1000000; i++)
    if (p[i] == 0) {
      for (long long j = i * i; j <= 1000000; j += i) p[j] = 1;
    }
  for (int i = 2; i <= 1000000; i++)
    if (p[i] == 0) st[++h1] = i;
  long long ans = 1e18;
  long long can = x / y;
  long long maybe, a, now, mid;
  for (int i = 1; i <= h1; i++) {
    a = st[i];
    now = 0;
    for (int j = a; j <= 1000000; j += a) {
      mid = max(j - a + 1, j - can);
      if (mid > j - a + 1) now += col(j - a + 1, mid - 1) * x;
      now += y * (col(mid, j - 1) * j - getsum(mid, j - 1));
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
