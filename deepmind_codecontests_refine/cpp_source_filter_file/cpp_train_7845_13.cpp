#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
template <typename T>
T gcd(T x, T y) {
  return y == 0 ? x : gcd(y, x % y);
}
template <typename T>
T lcm(const T &a, const T &b) {
  return (a * b) / gcd(a, b);
}
int t;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cout.precision(10);
  cout << fixed;
  cin >> t;
  while (t--) {
    int angle;
    cin >> angle;
    bool yes = false;
    for (int i = 2; i < 210; i++) {
      if (((i - 2) * 180) % i == 0 && ((i - 2) * 180) / i == angle) {
        yes = true;
        break;
      }
    }
    cout << (yes ? "YES\n" : "NO\n");
  }
  cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
  return 0;
}
