#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, b, p;
  cin >> n >> b >> p;
  long long int x, y;
  long long int ans1, ans2;
  ans2 = p * n;
  long long int q = pow(2, 20);
  while (n > 1) {
    while (q <= n) {
      x = q;
      y = n - x;
      x /= 2;
      n -= x;
      ans1 += x * (2 * b);
      ans1 += x;
    }
    q /= 2;
  }
  cout << ans1 << ' ' << ans2;
}
