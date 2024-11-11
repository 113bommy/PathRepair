#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 1e6 + 6;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (__typeof(n) i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long p = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i + 1] == 1) {
        p = 1;
        break;
      }
    }
    if (p)
      cout << 2 << "\n";
    else
      cout << 1 << "\n";
  }
  return 0;
}
