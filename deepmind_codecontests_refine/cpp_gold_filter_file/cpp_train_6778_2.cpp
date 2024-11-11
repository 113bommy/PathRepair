#include <bits/stdc++.h>
using namespace std;
long long calculate(int x, int y, int m) {
  long long ans = 0;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      int c = i * i + j * j;
      if (c % m == 0) {
        ans++;
      }
    }
  }
  return ans;
}
long long cal2(int m, int n) {
  long long ans = calculate(n % m, m, m);
  ans *= (n / m);
  ans *= 2LL;
  ans += calculate(n % m, n % m, m);
  return ans;
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long ans = calculate(min(m, n), min(m, n), m);
  if (m >= n) {
    cout << ans;
    return 0;
  }
  ans *= 1LL * ((n / m) * (n / m));
  ans += cal2(m, n);
  cout << ans;
  return 0;
}
