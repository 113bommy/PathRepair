#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 2 * 1e5 + 10;
int main() {
  long long int t;
  cin >> t;
  while (t-- > 0) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0 && k % 2 == 0) {
      cout << "YES" << endl;
      continue;
    }
    if (n % 2 == 0 && m % 2 == 1 && k % 2 == 0 && (n * m) - (k * 2) >= n) {
      cout << "YES" << endl;
      continue;
    }
    k = (n * m) / 2;
    if (n % 2 == 1 && m % 2 == 0 && k % 2 == 0 && (n * m) - (k * 2) >= n) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
