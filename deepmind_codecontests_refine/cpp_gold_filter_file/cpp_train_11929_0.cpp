#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
bool a[N];
long long sqr(long long a) { return a * a; }
int32_t main() {
  ios_base::sync_with_stdio(0);
  long long n, c1, c2, vz = 0;
  char c;
  cin >> n >> c1 >> c2;
  for (long long i = 0; i < n; i++) {
    cin >> c;
    a[i] = c - '0';
    if (a[i]) vz++;
  }
  long long ans = LLONG_MAX;
  for (long long cnt = 1; cnt <= vz; cnt++) {
    long long ig = n / cnt;
    long long md = n % cnt;
    long long ca =
        (cnt - md) * (c1 + c2 * sqr(ig - 1)) + md * (c1 + c2 * sqr(ig));
    ans = min(ans, ca);
  }
  cout << ans;
}
