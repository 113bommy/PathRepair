#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
void solve() {
  long long n, s;
  cin >> n >> s;
  long long tmp = n - 1, sm = s - tmp;
  if (tmp + 1 >= sm) {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "YES"
       << "\n";
  for (long long i = 0; i < tmp; i++) {
    cout << "1 ";
  }
  cout << sm << "\n";
  cout << n << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
