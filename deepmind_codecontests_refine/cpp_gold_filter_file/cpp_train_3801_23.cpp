#include <bits/stdc++.h>
using namespace std;
long long x, ans;
struct pp {
  long long n, m;
} p[8000005];
bool cmp(const pp &i, const pp &j) { return i.n < j.n; }
int main() {
  scanf("%I64d", &x);
  x *= 6;
  for (long long i = 1; i <= 4000000; i++) {
    if (x % (i + 1ll) == 0) {
      long long td = x / (i + 1ll);
      td = td + i * i - i;
      if (td % (i * 3ll) == 0) {
        long long m = td / (i * 3ll);
        if (i <= m) {
          p[++ans].n = i;
          p[ans].m = m;
          if (i != m) {
            p[++ans].n = m;
            p[ans].m = i;
          }
        }
      }
    }
  }
  sort(p + 1, p + ans + 1, cmp);
  printf("%I64d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%I64d %I64d\n", p[i].n, p[i].m);
}
