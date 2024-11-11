#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long lo = 5 - (i % 5);
    if (lo == 0) {
      lo = 5;
    }
    long long d = m - lo;
    if (d > 0) {
      ans++;
      ans += d / 5;
    }
  }
  cout << ans << endl;
}
