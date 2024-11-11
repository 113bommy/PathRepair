#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long q = min(n, m);
    long long ma = max(n, m);
    long long h = (ma - q);
    if (k < ma) {
      cout << -1 << endl;
      continue;
    }
    if (h == 0 && k == q) {
      printf("%lld\n", k);
      continue;
    }
    if (h & 1) {
      printf("%lld\n", k - 1);
      continue;
    } else {
      if ((k - q) % 2 == 0) {
        printf("%lld\n", k);
        continue;
      } else
        printf("%lld\n", k - 2);
      continue;
    }
  }
}
