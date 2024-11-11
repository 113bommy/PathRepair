#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    if (n < 2)
      cout << 1 << '\n';
    else
      cout << (n - 2) / x + 1 + bool((n - 2) % x) << '\n';
  }
}
