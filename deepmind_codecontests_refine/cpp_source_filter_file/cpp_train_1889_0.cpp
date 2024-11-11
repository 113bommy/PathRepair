#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[300005];
long long e;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (e) {
      ans += min(e, a[i] / 2);
      if (a[i] > e + e) {
        a[i] -= e + e;
        e = 0;
      } else {
        e -= (a[i] / 2);
        a[i] = 0;
      }
    }
    ans += a[i] / 3;
    long long r = a[i] % 3;
    e += r;
  }
  cout << ans << endl;
  return 0;
}
