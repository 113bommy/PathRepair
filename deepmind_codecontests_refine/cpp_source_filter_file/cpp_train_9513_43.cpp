#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
template <typename X>
inline X abs(const X &a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X &a) {
  return a * a;
}
const long double EPS = 1E-9, PI = 3.1415926535897932384626433832795;
const int N = 100 * 1000 + 13;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  if (m == 3) {
    if (n == 3) {
      cout << 0 << " " << 0 << endl;
      cout << 0 << " " << 1 << endl;
      cout << 1 << " " << 0 << endl;
      return 0;
    } else if (n == 4) {
      cout << 0 << " " << 0 << endl;
      cout << 0 << " " << 10 << endl;
      cout << 10 << " " << 0 << endl;
      cout << 1 << " " << 1 << endl;
      return 0;
    } else if (n >= 5) {
      cout << -1 << endl;
      return 0;
    }
  }
  long long int x = 1e7;
  for (long long int i = 0; i < n; i++) {
    cout << i << " " << x + i * i << endl;
  }
  for (long long int i = 0; i < n - m; i++) {
    cout << i << " " << -x - i * i << endl;
  }
}
