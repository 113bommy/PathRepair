#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205;
const int inf = 1e9 + 1e8;
const long long INF = 1e18 + 1e17;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
int a, b, c;
int main() {
  cin >> a >> b >> c;
  if (c == 0) {
    cout << (a == b ? "YES" : "NO") << endl;
    return 0;
  }
  if (c > 0) {
    cout << (b <= a || (b - a) % c ? "NO" : "YES") << endl;
  } else {
    c = abs(c);
    cout << (b >= a || (a - b) % c ? "NO" : "YES") << endl;
  }
  return 0;
}
