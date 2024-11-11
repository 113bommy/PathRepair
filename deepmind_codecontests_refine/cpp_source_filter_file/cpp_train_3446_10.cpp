#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 12, SQ = 550;
long long n, q, a[N], ls;
long long ps[N], ans[N];
long long A[N], B[N], qu[N];
bool cmp(long long f, long long s) { return B[f] < B[s]; }
int32_t main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  for (long long i = 0; i < q; i++) {
    cin >> A[i] >> B[i];
    qu[i] = i;
  }
  sort(qu, qu + q, cmp);
  for (long long ii = 0; ii < q; ii++) {
    long long i = qu[ii];
    if (B[i] < SQ) {
      if (B[i] != ls) {
        for (long long j = n; j; j--) ps[j] = ps[j + B[i]] + a[j];
        ls = B[i];
      }
      ans[i] = ps[A[i]];
    } else {
      long long ret = 0;
      for (; A[i] <= n; A[i] += B[i]) ret += a[A[i]];
      ans[i] = ret;
    }
  }
  for (long long i = 0; i < q; i++) cout << ans[i] << '\n';
  return 0;
}
