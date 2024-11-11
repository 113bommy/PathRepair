#include <bits/stdc++.h>
using namespace std;
const int inf = 987654321;
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  unsigned long long ans = 0;
  unsigned long long max1 = 0, max2 = 0;
  for (int i = 0; i < n; i++) {
    unsigned long long temp;
    scanf("%I64d", &temp);
    if (temp >= max1) {
      max2 = max1;
      max1 = temp;
    } else if (temp > max2) {
      max2 = temp;
    }
  }
  if (max1 == max2) {
    ans = max1 * m;
    printf("%I64u\n", ans);
    return 0;
  }
  int cnt = m / (k + 1);
  int rem = m % (k + 1);
  ans += cnt * (max1 * k + max2);
  ans += max1 * rem;
  printf("%I64u\n", ans);
  return 0;
}
