#include <bits/stdc++.h>
using namespace std;
int a[202000], n, k;
long long b[202000];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; ++i) scanf("%d", &a[i]);
  long long sum = 0;
  int r = n;
  for (int i = 0; i <= n; ++i) {
    b[i] = sum / 2;
    if (sum % 2 != 0) {
      r = i - 1;
      break;
    }
    sum /= 2;
    sum += a[i];
  }
  sum = 0;
  bool flag = 1;
  for (int i = n; i >= r + 1; --i) {
    sum = sum * 2 + a[i];
    if (abs(sum) > 1e18) {
      flag = 0;
      break;
    }
  }
  if (!flag) {
    puts("0");
    return 0;
  }
  int ans = 0;
  for (int i = r; i >= 0; --i) {
    if (abs(sum * 2 + b[i]) <= k) {
      if (i == n && b[i] == 0) {
      } else
        ++ans;
    }
    sum = sum * 2 + a[i];
    if (sum > 1e18) break;
  }
  printf("%d\n", ans);
  return 0;
}
