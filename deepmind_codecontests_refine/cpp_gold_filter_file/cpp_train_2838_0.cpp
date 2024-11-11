#include <bits/stdc++.h>
using namespace std;
using std::ios;
constexpr int MOD = 1e9 + 7;
constexpr int mod = 998244353;
long long hcf(long long a, long long b) {
  while (b) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b || b == c || c == a) {
      if (a == b && b < c)
        cout << "NO\n";
      else if (c == b && b < a)
        cout << "NO\n";
      else if (a == c && c < b)
        cout << "NO\n";
      else {
        cout << "YES\n";
        cout << max({a, b, c}) << ' ' << min({a, b, c}) << ' '
             << max(min({a, b, c}) - 1, 1) << '\n';
      }
    } else
      cout << "NO\n";
  }
}
