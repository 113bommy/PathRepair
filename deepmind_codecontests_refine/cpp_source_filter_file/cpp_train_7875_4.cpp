#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 2;
int q, cnt, num;
bool a[maxn];
int main() {
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int u;
      scanf("%d", &u);
      a[u] = true;
      cnt++;
      num = u;
    }
    if (type == 2) {
      int x, k, s;
      scanf("%d%d%d", &x, &k, &s);
      if (cnt == 1) {
        if (num + x <= s && num % k == 0 && x % k == 0)
          printf("%d\n", num);
        else
          printf("-1");
        continue;
      }
      int ans = -1;
      if (x % k == 0 && k >= 100)
        for (int i = k; i + x <= s; i += k)
          if (a[i]) ans = max(ans, i ^ x);
      if (x % k == 0 && k < 100)
        for (int i = s; ~i; i--) {
          int tmp = i ^ x;
          if (tmp % k == 0 && tmp + x <= s && a[tmp]) {
            ans = i;
            break;
          }
        }
      if (~ans) ans ^= x;
      printf("%d\n", ans);
    }
  }
  return 0;
}
