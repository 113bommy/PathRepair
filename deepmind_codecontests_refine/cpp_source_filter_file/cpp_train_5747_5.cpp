#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793;
const long long inf = 1e18 + 5;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
int main() {
  ios_base::sync_with_stdio(cin.tie(0) && 0);
  ;
  long long n;
  cin >> n;
  int p1 = 0;
  for (int i = 2; i <= (int)sqrt(n); i++) {
    if (n % i == 0) {
      p1 = i;
      while (n % i == 0) n /= i;
      break;
    }
  }
  if (p1 == 0) cout << n << '\n';
  if (n == 1)
    cout << p1 << '\n';
  else
    cout << 1 << '\n';
  return 0;
}
