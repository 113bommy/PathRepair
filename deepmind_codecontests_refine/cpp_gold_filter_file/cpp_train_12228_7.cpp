#include <bits/stdc++.h>
using namespace std;
struct aa {
  long long a, b, c;
} ans;
int main() {
  long long n, a, b, rt, i, j;
  bool fl;
  while (cin >> n >> a >> b) {
    n *= 6;
    if (n <= a * b) {
      printf("%I64d\n%I64d %I64d", a * b, a, b);
      continue;
    }
    if (a > b)
      fl = true, swap(a, b);
    else
      fl = false;
    rt = ceil(sqrt(6.0 * n));
    ans.a = (1LL << 60);
    for (i = a; i <= rt; i++) {
      j = ceil(n * 1.0 / i);
      if (j < b) break;
      if (ans.a > i * j) {
        ans.a = i * j;
        ans.b = i;
        ans.c = j;
      }
    }
    if (fl) swap(ans.b, ans.c);
    printf("%I64d\n%I64d %I64d\n", ans.a, ans.b, ans.c);
  }
  return 0;
}
