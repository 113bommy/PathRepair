#include <bits/stdc++.h>
using namespace std;
long long ans, s[100005], a[100005], n;
bool b[100005];
int main() {
  scanf("%I64d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%I64d", a + i), b[i] = 1, ans += a[i] * i, s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= 10; i++) {
    long long o = 1, p = 0;
    for (int j = 1; j <= n; j++) {
      if (b[j] && a[j] * o + s[n] - s[j] < 0) b[j] = 0;
      if (!b[j] && a[j] * o + s[n] - s[j] >= 0) b[j] = 1;
      if (b[j])
        s[j] = s[j - 1] + a[j], p += (o++) * a[j];
      else
        s[j] = s[j - 1];
    }
    ans = max(ans, p);
  }
  printf("%I64d\n", ans);
  return 0;
}
