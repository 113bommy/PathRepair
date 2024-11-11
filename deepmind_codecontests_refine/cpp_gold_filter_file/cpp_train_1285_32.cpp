#include <bits/stdc++.h>
using namespace std;
void Weapons19() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  Weapons19();
  long long k, b, n, t;
  cin >> k >> b >> n >> t;
  if (b >= t || t == 1) {
    cout << n;
    return 0;
  }
  long long p = k, a = 0, ans = 0;
  while (1) {
    if (a + p > t - b || ans == n) break;
    a = a + b * p;
    p = p * k;
    ans++;
  }
  cout << n - ans;
}
