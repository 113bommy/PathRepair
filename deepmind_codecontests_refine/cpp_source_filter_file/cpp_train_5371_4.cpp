#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int a[1000050];
int main() {
  long long int n;
  cin >> n;
  long long int i;
  long long int g = 1, ans = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    g = gcd(g, a[i]);
  }
  if (g > 1) {
    cout << "YES" << endl;
    cout << "0" << endl;
    return 0;
  }
  for (i = 0; i < n - 1; i++) {
    if (a[i] % 2 == 1 && a[i + 1] % 2 == 1) {
      ans += 1;
      i++;
    } else if (a[i] % 2 == 1 && a[i + 1] % 2 == 0)
      ans += 2;
  }
  if (a[i] % 2) ans += 2;
  cout << "YES" << endl;
  cout << ans << endl;
  return 0;
}
