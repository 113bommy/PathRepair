#include <bits/stdc++.h>
using namespace std;
const long long INF = ~0ull >> 2;
int _;
int main() {
  for (scanf("%d", &_); _; _--) {
    long long n;
    scanf("%lld", &n);
    int ccount[105] = {0};
    int now = 0, p = -1;
    while (n) {
      ccount[now++] = n % 3;
      n /= 3;
      if (ccount[now - 1] == 2) p = now - 1;
    }
    now--;
    if (p == -1) {
      long long ans = 0;
      for (int i = now; i >= 0; i--) ans = ans * 3 + ccount[i];
      cout << ans << endl;
    } else {
      while (ccount[p] >= 2) {
        ccount[p++] = 0;
        ccount[p] += 1;
      }
      now = max(now, p);
      for (int i = 0; i < now; i++) ccount[i] = 0;
      long long ans = 0;
      for (int i = now; i >= 0; i--) ans = ans * 3 + ccount[i];
      cout << ans << endl;
    }
  }
  return 0;
}
