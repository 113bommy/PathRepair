#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000 + 30;
int num[MAXN], endp[MAXN], arr[MAXN];
int main() {
  int n, q, t, x;
  scanf("%d%d", &n, &q);
  int pos = 1, ans = 0, fr = 0;
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &t, &x);
    if (t == 1) {
      ans++;
      num[x]++;
      arr[pos++] = x;
    } else if (t == 2) {
      endp[x] = pos;
      ans -= num[x];
      num[x] = 0;
    } else if (t == 3) {
      if (x > t) {
        for (int j = t + 1; j <= x; j++) {
          if (j >= endp[arr[j]]) {
            ans--;
            num[arr[j]]--;
          }
        }
        t = x;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
