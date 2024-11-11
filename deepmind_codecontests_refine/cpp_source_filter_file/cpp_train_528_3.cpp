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
      printf("%lld", k);
      continue;
    }
    if (h & 1) {
      printf("%lld", k - 1);
      continue;
    } else {
      if ((k - q) % 2 == 0) {
        printf("%lld", k);
        continue;
      } else
        printf("%lld", k - 2);
      continue;
    }
  }
}
