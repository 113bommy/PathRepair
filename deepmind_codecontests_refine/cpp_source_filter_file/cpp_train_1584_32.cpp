#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t;
  t = 1;
  while (t--) {
    int64_t n;
    cin >> n;
    if (n == 1)
      cout << 9 << " " << 8;
    else
      cout << (n * n) + n << " " << (n * n);
  }
}
