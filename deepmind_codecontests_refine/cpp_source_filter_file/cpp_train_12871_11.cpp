#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  long long ans = 1000000007;
  long long temp = 0;
  cout << ans << ' ' << ans << endl;
  long long cnt = m;
  for (long long i = 1; i <= n - 1; i++) {
    if (i == n - 1) {
      cout << i << ' ' << i + 1 << ' ' << ans - temp << endl;
      cnt--;
    } else {
      cout << i << ' ' << i + 1 << ' ' << "1" << endl;
      cnt--;
      temp++;
    }
  }
  while (cnt > 0) {
    for (long long i = 1; i <= n; i++) {
      if (cnt <= 0) break;
      for (long long j = i + 2; j <= n; j++) {
        if (cnt <= 0) break;
        cout << i << ' ' << j << ' ' << ans + 1 << endl;
        cnt--;
      }
    }
  }
  return 0;
}
