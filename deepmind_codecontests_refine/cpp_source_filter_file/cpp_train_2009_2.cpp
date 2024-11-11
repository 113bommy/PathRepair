#include <bits/stdc++.h>
using namespace std;
const long long int MOD1 = 1e9 + 7;
const long long int MOD2 = 998244353;
long long int mod = MOD1;
long long int po(long long int x, long long int y) {
  y %= mod;
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(a % b, b);
}
void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (min(a, b) < max(c, d)) {
    cout << -1;
    return;
  }
  if (abs(c - d) > 1) {
    cout << -1;
    return;
  }
  string ans;
  if (c > d) {
    for (int ii = 0; ii < c; ii++) {
      ans += "47";
      a--;
      b--;
    }
  } else if (d > c) {
    for (int ii = 0; ii < d; ii++) {
      ans += "74";
      a--;
      b--;
    }
  } else {
    if (a > 1) {
      ans += "4";
      a--;
      for (int ii = 0; ii < d; ii++) {
        ans += "74";
        a--;
        b--;
      }
    } else {
      ans += "7";
      b--;
      for (int ii = 0; ii < d; ii++) {
        ans += "47";
        a--;
        b--;
      }
    }
  }
  if (a < 0 || b < 0) {
    cout << -1;
    return;
  }
  int x = -1, y = -1;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == '4') {
      x = i;
      break;
    }
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    if (ans[i] == '7') {
      y = i;
      break;
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == x && a > 0) {
      while (a) {
        cout << "4";
        a--;
      }
    } else if (i == y && b > 0) {
      while (b) {
        cout << "7";
        b--;
      }
    }
  }
}
int main() {
  {
    solve();
    cout << "\n";
    ;
  }
}
