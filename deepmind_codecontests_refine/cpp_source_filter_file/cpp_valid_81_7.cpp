#include <bits/stdc++.h>
using namespace std;
const int mod1 = 998244353;
const int mod2 = 1000000007;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int power(int x, int y, int md = -1) {
  int res = 1;
  if (md == -1) {
    while (y) {
      if (y & 1) res = (res * x);
      x *= x;
      y >>= 1;
    }
    return res;
  } else {
    x %= md;
    while (y) {
      if (y & 1) res = (res * x) % md;
      x *= x;
      if (x >= md) x %= md;
      y >>= 1;
    }
    return res;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  int testcases;
  cin >> testcases;
  while (testcases--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int a[n], b[n + 1];
    for (int i = 0; i < n; i += 2) {
      if (s[i] == '+') {
        a[i] = 1;
      } else {
        a[i] = -1;
      }
    }
    for (int i = 1; i < n; i += 2) {
      if (s[i] == '-') {
        a[i] = 1;
      } else {
        a[i] = -1;
      }
    }
    b[0] = 0;
    b[1] = a[0];
    for (int i = 1; i < n; i++) {
      b[i + 1] = b[i] + a[i];
    }
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      if (b[r] == b[l - 1]) {
        cout << 0 << '\n';
      } else {
        cout << 2 - ((r - l - 1) % 2) << '\n';
      }
    }
  }
}
