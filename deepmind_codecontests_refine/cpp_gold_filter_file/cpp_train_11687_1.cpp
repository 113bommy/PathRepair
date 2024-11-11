#include <bits/stdc++.h>
using namespace std;
const long long int N = 350010;
long long int t, n, k, l, d[N], can[N];
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld", &n, &k, &l);
    long long int minn = k, ok = 0, yorn = 1;
    for (long long int i = 1; i <= n; i++) {
      scanf("%lld", &d[i]);
      d[i] = l - d[i];
      if (d[i] >= k) {
        can[i] = i;
        minn = k;
        ok = 0;
      } else {
        can[i] = can[i - 1];
        if (minn + can[i] <= i) {
          ok = 1;
        }
        if (ok == 1) {
          if (i - (minn + can[i]) > d[i]) {
            yorn = 0;
          }
        } else {
          minn = min(minn, d[i] + i - can[i]);
        }
      }
    }
    if (yorn == 1) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}
