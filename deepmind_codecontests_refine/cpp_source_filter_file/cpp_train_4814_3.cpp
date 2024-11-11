#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100005;
LL a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    LL sum = 0;
    LL x;
    scanf("%d%lld", &n, &x);
    int q = n;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    sort(a + 1, a + n + 1);
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
      if (sum * 1.0 / q * 1.0 >= x * 1.0) {
        printf("%lld\n", q);
        flag = false;
        break;
      }
      sum -= a[i], --q;
    }
    if (flag) printf("%lld\n", q);
  }
  return 0;
}
