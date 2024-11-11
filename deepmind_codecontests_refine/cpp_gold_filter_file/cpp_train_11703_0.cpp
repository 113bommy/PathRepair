#include <bits/stdc++.h>
using namespace std;
const int N = 4010;
int h[N * 9 + 10], sum[N];
char str[N];
int main() {
  long long a;
  scanf("%I64d", &a);
  scanf("%s", str);
  int len = strlen(str);
  sum[0] = str[0] - '0';
  for (int i = 1; i < len; i++) sum[i] = sum[i - 1] + str[i] - '0';
  memset(h, 0, sizeof(h));
  for (int i = 0; i < len; i++)
    for (int j = i; j < len; j++) {
      h[sum[j] - (i ? sum[i - 1] : 0)]++;
    }
  if (a == 0) {
    long long ans;
    ans = 2LL * h[0] * (1LL * len * (len + 1) / 2 - h[0]);
    ans += 2LL * h[0] * (h[0] + 1) / 2;
    ans -= h[0];
    printf("%I64d\n", ans);
    return 0;
  }
  long long ans = 0, tmp;
  for (long long i = 1; i <= N * 9 && i * i <= a; i++) {
    tmp = a / i;
    if (tmp > 4010 * 9) continue;
    if (a % i == 0) ans += ((i == a / i) ? 1LL : 2LL) * h[i] * h[a / i];
  }
  printf("%I64d\n", ans);
  return 0;
}
