#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  if (y == 0)
    return 1;
  else {
    long long int p = power(x, y / 2);
    if (y % 2 == 0)
      return (p * p) % 1000000007LL;
    else
      return (x * ((p * p) % 1000000007LL)) % 1000000007LL;
  }
}
long long int gcd(long long int x, long long int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], c = 0;
    map<long long int, long long int> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 1)
        mp[i] = 1;
      else {
        mp[i] = 2;
        c++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (mp[i] == 2) {
        cout << 1 << "\n" << i;
        break;
      }
    }
    if (c == 0) {
      if (n >= 2) {
        cout << 2 << "\n" << 1 << " " << 2;
      } else
        cout << -1;
    }
    cout << "\n";
  }
}
