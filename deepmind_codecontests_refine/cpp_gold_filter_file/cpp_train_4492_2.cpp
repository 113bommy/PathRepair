#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    long long n, x, y;
    cin >> n >> x >> y;
    long long ans = (y - n + 1) * (y - n + 1) + n - 1;
    if (y < n) {
      cout << -1;
      return 0;
    }
    if (ans < x)
      cout << -1;
    else {
      for (long long int i = 0; i < n - 1; i++) {
        cout << 1 << "\n";
      }
      cout << y - n + 1;
    }
  }
  return 0;
}
