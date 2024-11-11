#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const double eps = 1e-8;
const int maxn = 2e5 + 5;
const int INF = 1e9;
int main(void) {
  long long n;
  long long q, x;
  cin >> n >> q;
  n = 2 * n;
  while (q--) {
    cin >> x;
    while (x % 2 == 0) {
      x += (n - x) / 2;
    }
    cout << (x + 1) / 2 << endl;
  }
  return 0;
}
