#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10;
const long long M = 2111;
const long long INF = 1e18;
const long long inf = -1e18;
const long long MOD = 1e9 + 7;
const long long xesh = 31;
long long a, b, k, t;
int main() {
  long long o = 1;
  cin >> o;
  while (o--) {
    cin >> a >> b;
    k = b;
    t = 0;
    while (k > 0) {
      t++;
      k /= 10;
    }
    cout << a * (t - 1) << "\n";
  }
}
