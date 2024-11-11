#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int m) {
  if (b == 0) return (1);
  long long int sol = power(a, b / 2, m);
  sol = (sol * sol) % m;
  if (b % 2 == 1) sol = (sol * a) % m;
  return sol;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else {
    return gcd(b, a % b);
  }
}
int a[100005];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] <= i) {
      ans = i;
      break;
    }
  }
  ans++;
  cout << ans << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
