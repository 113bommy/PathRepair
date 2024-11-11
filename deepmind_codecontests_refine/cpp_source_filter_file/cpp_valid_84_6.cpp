#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, second;
  cin >> n >> second;
  long long x = (n + 1) / 2;
  cout << second / x << '\n';
}
signed main() {
  long long n = 1;
  cin >> n;
  while (n--) {
    solve();
  }
}
