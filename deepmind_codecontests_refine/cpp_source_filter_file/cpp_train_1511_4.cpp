#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main() {
  int n;
  scanf("%d", &n);
  int min1 = 0x3f3f3f3f;
  int max1 = -0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
    min1 = min(min1, x);
    max1 = max(max1, x);
  }
  long long cnt = 0;
  for (int i = 0; i <= max1; i++) {
    a[i + 1] += a[i] / 2;
    if (i == max1 && a[i] / 2 > 0) max1++;
    if (a[i] % 2 == 1) cnt++;
  }
  printf("%I64d\n", cnt);
  return 0;
}
