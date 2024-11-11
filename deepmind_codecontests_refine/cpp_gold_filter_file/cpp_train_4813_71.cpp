#include <bits/stdc++.h>
using namespace std;
long long int f(long long int b, long long int c) {
  long long int c1 = (c / b) * b;
  long long int c2 = (c / b + 1) * b;
  if (!c1) c1 = c2;
  if (abs(c1 - c) < abs(c2 - c))
    return c1;
  else
    return c2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(20);
  long long int tt;
  cin >> tt;
  while (tt--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int a1, b1, c1;
    long long int ans = 1000000007;
    long long int A, B, C;
    long long int cnt = 0;
    for (auto i = 1; i <= 10000; i++) {
      a1 = i;
      cnt = abs(a - a1);
      for (long long int j = a1; j <= (10000 + a1); j += a1) {
        b1 = j;
        c1 = f(b1, c);
        cnt += (abs(b - b1) + abs(c - c1));
        if (cnt < ans) {
          ans = cnt;
          A = a1;
          B = b1;
          C = c1;
        }
        cnt -= (abs(b - b1) + abs(c - c1));
      }
    }
    cout << ans << '\n';
    cout << A << ' ' << B << ' ' << C << '\n';
  };
  return 0;
}
