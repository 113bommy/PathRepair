#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, k, c, ans = 0, n1;
  cin >> n >> a >> b >> c;
  if (a <= b - c)
    ans = n / a;
  else {
    k = max(0LL, (n - b) / (b - c));
    n1 = n - (k + 1) * (b - c);
    if (n1 >= 0) {
      ans = k + 1 + max(n1 / a, n1 / b);
    }
    n -= k * (b - c);
    ans = max(ans, k + max(n / a, n / b));
  }
  cout << ans << endl;
}
