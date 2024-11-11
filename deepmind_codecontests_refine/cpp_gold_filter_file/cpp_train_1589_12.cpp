#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 3e2 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  long long t1;
  cin >> t1;
  while (t1--) {
    long long x, y, n;
    cin >> x >> y >> n;
    long long k = n % x;
    long long diff = k - y;
    if (diff >= 0)
      n = n - diff;
    else
      n = n - diff - x;
    cout << n << endl;
  }
  return 0;
}
