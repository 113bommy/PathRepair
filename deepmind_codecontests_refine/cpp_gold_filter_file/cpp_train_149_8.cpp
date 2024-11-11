#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int lcm(int x, int y) {
  long long Lcm = 1LL * x * y;
  Lcm = Lcm / gcd(x, y);
  return Lcm;
}
int a[600], b[1009], aa[1009][1009];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) cin >> b[i];
  long long int l = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      if (b[j] != b[i] && aa[b[i]][b[j]] == 0) {
        l += a[b[i]];
        aa[b[i]][b[j]] = 1;
        aa[b[j]][b[i]] = 0;
      }
    }
  }
  cout << l << endl;
  return 0;
}
