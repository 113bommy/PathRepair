#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, x, y;
  cin >> n >> x >> y;
  long long c =
      ((y - n + (long long)1) * (y - n + (long long)1) + n - (long long)1);
  if ((n > y) || c <= x) {
    cout << -1 << "\n";
  } else {
    for (int i = 1; i < n; i++) cout << "1 ";
    cout << y - (n - 1);
  }
}
int32_t main() {
  { solve(); }
}
