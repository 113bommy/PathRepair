#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 1;
const long long PRIME = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if ((a + b) & 1) {
    bool flag0 = 0, flag1 = 0;
    if (a > 0 && (b > 0 || c > 0)) {
      flag0 = 1, flag1 = 1;
    } else if (d > 0 && (b > 0 || c > 0)) {
      flag0 = 1, flag1 = 1;
    } else if (a > 0 && (b == 0 && c == 0)) {
      flag0 = 1;
    } else if (d > 0 && (b == 0 && c == 0)) {
      flag0 = 1;
    } else if ((a == 0 && d == 0) && (c > 0 || b > 0)) {
      flag1 = 1;
    }
    if (flag0 && flag1) {
      cout << "Ya Ya Tidak Tidak\n";
    } else if (flag0) {
      cout << "Ya Tidak Tidak Tidak\n";
    } else if (flag1) {
      cout << "Tidak Ya Tidak Tidak\n";
    }
  } else {
    bool flag0 = 0, flag1 = 0;
    if (a > 0 && (b > 0 || c > 0)) {
      flag0 = 1, flag1 = 1;
    } else if (d > 0 && (b > 0 || c > 0)) {
      flag0 = 1, flag1 = 1;
    } else if (a > 0 && (b == 0 && c == 0)) {
      flag0 = 1;
    } else if (d > 0 && (b == 0 && c == 0)) {
      flag0 = 1;
    } else if ((a == 0 && d == 0) && (c > 0 || b > 0)) {
      flag1 = 1;
    }
    if (flag0 && flag1) {
      cout << "Tidak Tidak Ya Ya\n";
    } else if (flag0) {
      cout << "Tidak Tidak Ya Tidak\n";
    } else if (flag1) {
      cout << "Tidak Tidak Tidak Ya\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
