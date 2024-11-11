#include <bits/stdc++.h>
using namespace std;
long long int ans[100005];
int main() {
  long long int N, M, ok = 1, i, j, t, a, b, can = 0;
  scanf("%lld", &N);
  for (i = 0; i < N / 2; i++) {
    scanf("%lld", &t);
    can = 0;
    for (j = 1; j * j <= t; j++) {
      if (t % j == 0) {
        a = j;
        b = t / j;
        if ((a + b) % 2 == 0) {
          if (i == 0 || (b - a) / 2 > ans[i * 2 - 1]) {
            can = 1;
            ans[2 * i] = (b - a) / 2;
            ans[2 * i + 1] = (b + a) / 2;
          }
        }
      }
    }
    ok = ok && can;
  }
  if (ok) {
    printf("Yes\n");
    for (i = 0; i < N; i++) {
      if (i == 0)
        printf("%lld ", ans[i] * ans[i]);
      else
        printf("%lld ", ans[i] * ans[i] - ans[i - 1] * ans[i - 1]);
    }
  } else
    printf("No\n");
  return 0;
}
