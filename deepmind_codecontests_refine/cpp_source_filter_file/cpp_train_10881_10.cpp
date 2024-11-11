#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
int main() {
  int t = 1;
  while (t--) {
    ll n;
    cin >> n;
    ll ans = (n / 2) + (n / 3) + (n / 5) + (n / 7);
    ans = ans - (n / 6) - (n / 10) - (n / 14) - (n / 15) - (n / 21) - (n / 35) +
          (n / 210);
    ans = ans + (n / 30) + (n / 105) + (n / 70) + (n / 42);
    cout << n - ans << endl;
  }
  return 0;
}
