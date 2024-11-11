#include <bits/stdc++.h>
using namespace std;
int QQ, a, b, cnt[5000001], sum[5000001];
int main() {
  for (int i = 2; i <= 5000000; i++)
    if (!cnt[i])
      for (int j = i; j <= 5000000; j += i) cnt[j] = cnt[j / i] + 1;
  for (int i = 2; i <= 5000000; i++) sum[i] = sum[i - 1] + cnt[i];
  scanf("%d", &QQ);
  while (QQ--) {
    scanf("%d%d", &a, &b);
    printf("%d\n", sum[a] - sum[b]);
  }
  return 0;
}
