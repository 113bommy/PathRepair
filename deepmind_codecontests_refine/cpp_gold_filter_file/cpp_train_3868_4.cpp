#include <bits/stdc++.h>
using namespace std;
int num[20];
int main() {
  long long n, k;
  scanf("%lld", &n);
  k = n;
  int cnt = 0;
  while (k) {
    num[cnt++] = k % 10;
    k /= 10;
  }
  long long ans = 0;
  for (int i = 0; i < cnt; i++) {
    long long sum = 1;
    if (i) {
      if (num[i] - 1 <= 0 && i != cnt - 1) continue;
      if (num[i] - 1 <= 0 && i == cnt - 1) cnt--;
      num[i] -= 1;
      for (int j = 0; j < i; j++) num[j] = 9;
    }
    for (int j = 0; j < cnt; j++) sum *= num[j];
    ans = max(sum, ans);
  }
  printf("%lld\n", ans);
  return 0;
}
