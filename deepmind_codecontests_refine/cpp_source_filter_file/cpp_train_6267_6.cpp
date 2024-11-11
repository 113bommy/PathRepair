#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int s, n, a[N];
long long ans = 1e13;
long long solve(int x) {
  long long res = 0, sum = 0;
  for (long long i = 0; i < n - 1; i++) {
    sum += a[i];
    res += min(sum % x, x - (sum % x));
  }
  if (res == 0) cout << x << " " << s << endl;
  return res;
}
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ;
    s += a[i];
  }
  if (s == 1) return cout << -1, 0;
  ans = min(ans, solve(s));
  ;
  for (int i = 2; i * i <= n; i++) {
    if (s % i == 0) ans = min(ans, min(solve(i), solve(s / i)));
    ;
  }
  cout << ans;
}
