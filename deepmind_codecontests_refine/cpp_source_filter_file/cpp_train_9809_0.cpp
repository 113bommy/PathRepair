#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool mod(long double a, long double b) { return a / b - floor(a / b); }
int occurs(vector<int> v, int n) {
  auto it = lower_bound(((v)).begin(), ((v)).end(), (n));
  auto it1 = upper_bound(((v)).begin(), ((v)).end(), (n));
  int x = it1 - it;
  return x;
}
long double max(long double a, long double b) { return a < b ? b : a; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int a[n];
    int c = 0;
    for (int(i) = 0; (i) < (n); ++(i)) {
      if (s[i] == '0')
        c++;
      else
        c--;
      a[i] = c;
    }
    sort(a, a + n);
    int ans = 0;
    if (c == 0) {
      for (int(i) = 0; (i) < (n); ++(i)) {
        if (a[i] == x) {
          ans = -1;
          break;
        }
      }
      if (x == 0 && ans == 0) ans = 1;
      cout << ans << '\n';
    } else {
      if ((x >= 0 && c > 0) || (x <= 0 && c < 0)) {
        if (c > 0) {
          for (int(i) = 0; (i) < (n); ++(i)) {
            if ((x - a[i]) % c == 0 && (x - a[i]) >= 0) ans++;
          }
        } else {
          for (int(i) = 0; (i) < (n); ++(i)) {
            if ((x - a[i]) % c == 0 && (x - a[i]) <= 0) ans++;
          }
        }
        if (x == 0) ans++;
        cout << ans << '\n';
      } else {
        if (c > 0) {
          for (int(i) = 0; (i) < (n); ++(i)) {
            if ((x - a[i]) % c == 0 && (x - a[i]) > 0) ans++;
          }
        } else {
          for (int(i) = 0; (i) < (n); ++(i)) {
            if ((x - a[i]) % c == 0 && (x - a[i]) < 0) ans++;
          }
        }
        if (x == 0) ans++;
        cout << ans << '\n';
      }
    }
  }
  return 0;
}
