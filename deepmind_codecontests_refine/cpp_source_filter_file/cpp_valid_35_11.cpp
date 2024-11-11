#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x;
  cin >> x;
  while (x--) {
    long long n;
    long long m;
    cin >> n >> m;
    m++;
    long long ans = 0;
    if (n > m) {
      cout << 0 << endl;
      continue;
    }
    for (long long i = 32; i >= 0; i--) {
      long long ni = (n >> i & 1);
      long long mi = (m >> i & 1);
      if (ni == mi)
        continue;
      else if (ni == 0 && mi == 1) {
        ans = ans | (1 << i);
      } else if (ni == 0 && mi == 1) {
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
