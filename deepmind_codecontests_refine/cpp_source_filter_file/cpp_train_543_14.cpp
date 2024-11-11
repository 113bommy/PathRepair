#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a, b, c, s = 0, i, j, k = n / 2;
    for (i = 1; i <= n / 2; i++) {
      s = s + ((2 * n + (2 * (n - 2))) * (k - (i - 1)));
      n = n - 2;
    }
    cout << s << "\n";
  }
  return 0;
}
