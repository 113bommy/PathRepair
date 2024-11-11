#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    if (2 * a <= b) {
      cout << n << "\n";
    } else {
      cout << ((n / 2) * b) + ((n % 2) * a) << "\n";
    }
  }
  return 0;
}
