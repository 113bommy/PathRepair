#include <bits/stdc++.h>
using namespace std;
const int mod = int(1e9 + 7), MAXN = int(2e5 + 1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, q;
  cin >> n >> q;
  while (q--) {
    long long x;
    cin >> x;
    long long l = 1, r = 2 * n - 1;
    while (x % 2 == 0) {
      long long s = (l + r) / 2;
      x = s + x / 2 - (l - 1) / 2;
      l = s + 1;
    }
    printf("%lld\n", (x + 1) / 2);
  }
  return 0;
}
