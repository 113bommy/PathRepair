#include <bits/stdc++.h>
using namespace std;
long double po(long double x, long long n) {
  long double result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = result * x;
    x = x * x;
    n = n / 2;
  }
  return result;
}
void solve() {
  long long n;
  long double a;
  cin >> a >> n;
  cout << setprecision(20) << a + a * ((po(1.000000011, n) - 1));
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
