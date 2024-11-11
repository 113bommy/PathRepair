#include <bits/stdc++.h>
using namespace std;
char c1[1005], c2[1005], l;
long long f[100005][2], ans, k;
bool pd;
int main() {
  scanf("%s", c1);
  scanf("%s", c2);
  scanf("%lld", &k);
  l = strlen(c1);
  f[0][0] = 1;
  for (register long long i = 1; i <= k; i = -~i) {
    f[i][0] = ((l - 1) * f[i - 1][1]) % 1000000007;
    f[i][1] = (((l - 2) * f[i - 1][1]) % 1000000007 + f[i - 1][0]) % 1000000007;
  }
  for (register long long i = 0; i < l; i = -~i) {
    pd = false;
    for (register long long j = 0; j < l; j = -~j)
      if (c1[(i + j) % l] != c2[j]) {
        pd = true;
        break;
      }
    if (!pd) {
      if (i)
        ans = (ans + f[k][1]) % 1000000007;
      else
        ans = (ans + f[k][0]) % 1000000007;
    }
  }
  printf("%lld", ans);
  return 0;
}
