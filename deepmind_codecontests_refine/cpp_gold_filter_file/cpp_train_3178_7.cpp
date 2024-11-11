#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, b;
  cin >> n >> b >> p;
  int ans = 0, ans1 = 0;
  ans1 = p * n;
  while (n > 1) {
    int t = log2(n);
    int m = pow(2, t);
    ans += m * b + m / 2;
    int add = n - m;
    n = m / 2 + add;
  }
  cout << ans << " " << ans1;
  return 0;
}
