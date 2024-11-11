#include <bits/stdc++.h>
using namespace std;
int const N = (int)2e6 + 1, INF = (int)1e9 + 1, MOD = (int)1e9 + 7;
long long mypow(long long a, long long b) {
  long long rv = 1;
  while (b) {
    if (b % 2) rv = rv * a;
    a = a * a;
    b /= 2;
  }
  return rv;
}
bool ok, used[N];
long long n, m, ans, cur, a, b, c, t, second[5000];
vector<long long> v;
int main() {
  cin >> n >> a >> b >> c >> t;
  for (int i = 1; i <= n; i++) cin >> second[i];
  sort(second + 1, second + 1 + n);
  if (b >= c) {
    cout << n * a;
  } else {
    for (int i = 1; i <= n; i++) {
      ans += (t - second[i]) * (c - b);
    }
    cout << ans + n * a;
  }
  return 0;
}
