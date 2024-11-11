#include <bits/stdc++.h>
using namespace std;
const int maxn = 212345;
int n;
int b[maxn];
long long a[maxn];
int main() {
  scanf("%d", &n);
  int mn = 1e9, mx = 0;
  for (int(i) = (0); (i) <= ((n)-1); (i)++) {
    scanf("%d", b + i);
    mn = min(mn, b[i]);
    mx = max(mx, b[i]);
  }
  if (!mx) {
    puts("YES");
    for (int(i) = (0); (i) <= ((n)-1); (i)++) printf("1 ");
    return 0;
  }
  if (mn == mx) {
    puts("NO");
    return 0;
  }
  puts("YES");
  int peak = -1;
  for (int(i) = (0); (i) <= ((n)-1); (i)++)
    if (b[i] == mx) {
      peak = i;
      break;
    }
  if (!peak) {
    for (int i = n - 1; b[i] == mx; i--) peak = i;
  }
  a[peak] = mx;
  for (int(i) = (1); (i) <= (n - 1); (i)++) {
    if (b[(peak - i + n) % n] == 0 && a[(peak - i + n + 1) % n] == mx)
      a[(peak - i + n) % n] = mx * 2;
    else
      a[(peak - i + n) % n] = a[(peak - i + n + 1) % n] + b[(peak - i + n) % n];
  }
  for (int(i) = (0); (i) <= ((n)-1); (i)++) printf("%lld ", a[i]);
}
