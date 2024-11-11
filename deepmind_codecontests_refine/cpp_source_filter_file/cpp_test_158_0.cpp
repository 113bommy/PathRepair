#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long num, id;
  inline bool operator<(const Node x) const {
    if (num != x.num) return num < x.num;
    return id < x.id;
  }
} a[100005];
long long T, n, m, Ans, sum, b[11], r[11], ans[100005];
char s[11][100005];
signed main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (long long i = 1; i <= n; i++) scanf("%d", &r[i]);
    for (long long i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
    }
    Ans = 0;
    for (long long k = 0; k < (1 << n); k++) {
      long long now = k;
      sum = 0;
      for (long long i = n; i >= 1; i--) {
        b[i] = now % 2;
        if (b[i]) {
          sum -= r[i];
        } else {
          sum += r[i];
        }
        now /= 2;
      }
      for (long long i = 1; i <= m; i++) {
        a[i].id = i;
        a[i].num = 0;
        for (long long j = 1; j <= n; j++) {
          if (s[j][i] == '1') {
            if (b[j]) {
              a[i].num++;
            } else {
              a[i].num--;
            }
          }
        }
      }
      sort(a + 1, a + m + 1);
      for (long long i = 1; i <= m; i++) sum += a[i].num * i;
      if (sum > Ans) {
        Ans = sum;
        for (long long i = 1; i <= m; i++) ans[a[i].id] = i;
      }
    }
    for (long long i = 1; i <= m; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
