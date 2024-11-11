#include <bits/stdc++.h>
using namespace std;
const long long int INF = 9223372036854775807LL;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroint-loops")
long long int power(long long int b, long long int e, long long int m) {
  if (b == 0) return 0;
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long int power(long long int b, long long int e) {
  if (b == 0) return 0;
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
bool isPowerOfTwo(long long int x) { return (x && !(x & (x - 1))); }
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i <= n / 3; i++) {
    for (long long int j = 0; j <= n / 5; j++) {
      for (long long int k = 0; k <= n / 7; k++) {
        if (i * 3 + j * 5 + k * 7 == n) {
          cout << i << " " << j << " " << k;
          return;
        }
      }
    }
  }
  cout << -1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
    cout << "\n";
  }
  return 0;
}
