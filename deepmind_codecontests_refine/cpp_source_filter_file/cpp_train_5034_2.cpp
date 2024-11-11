#include <bits/stdc++.h>
using namespace std;
int a[100005];
map<long long, int> m;
int main() {
  int n, i;
  scanf("%d", &n);
  long long sum = 0, ans = 0;
  m.clear();
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
    if (i < n - 1) m[sum]++;
  }
  if (sum % 3) {
    printf("0\n");
    return 0;
  }
  long long t = 0;
  sum /= 3;
  for (i = 0; i < n; i++) {
    t += a[i];
    m[t]--;
    if (t == sum) ans += m[t + sum];
  }
  printf("%I64d\n", ans);
  return 0;
}
