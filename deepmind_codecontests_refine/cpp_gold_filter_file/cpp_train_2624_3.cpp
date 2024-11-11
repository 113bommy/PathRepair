#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t, n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long c, sum;
    cin >> c >> sum;
    if (c >= sum)
      cout << sum << endl;
    else {
      long long y = 0;
      long long z = sum / c;
      long long x = sum % c;
      for (long long i = 1; i <= x; i++) y = y + ((z + 1) * (z + 1));
      for (long long i = 1; i <= (c - x); i++) y = y + (z * z);
      cout << y << endl;
    }
  }
}
