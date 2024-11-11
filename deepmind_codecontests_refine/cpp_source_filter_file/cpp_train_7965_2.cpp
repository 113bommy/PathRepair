#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500010];
long long preA[500010], preB[500010];
char s[500010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
  scanf("%s", s);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'A')
      preA[i] = preA[i - 1] + a[i], preB[i] = preB[i - 1];
    else
      preA[i] = preA[i - 1], preB[i] = preB[i - 1] + a[i];
  }
  long long res = max(preA[n], preB[n]);
  for (int i = 1; i < n; ++i) {
    long long tmp =
        max(preA[i] + preB[n] - preB[i], preB[i] + preA[n] - preA[i]);
    res = max(res, tmp);
  }
  printf("%lld", res);
  return 0;
}
