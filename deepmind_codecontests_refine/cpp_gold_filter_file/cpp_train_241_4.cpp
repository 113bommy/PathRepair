#include <bits/stdc++.h>
using namespace std;
long long a[3];
int main() {
  scanf("%I64d%I64d%I64d", &a[0], &a[1], &a[2]);
  long long ans = a[0] + a[1] + a[2];
  for (int i = 0; i <= 2; i++) {
    long long A = a[i], B = a[(i + 1) % 3];
    if (((A - B) < 0 ? -(A - B) : (A - B)) & 1) continue;
    ans =
        ((ans) < (((A) > (B) ? (A) : (B))) ? (ans) : (((A) > (B) ? (A) : (B))));
  }
  printf("%I64d\n", ans);
  return 0;
}
