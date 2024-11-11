#include <bits/stdc++.h>
using namespace std;
int n, a, b, T;
int ans;
int sum[500010];
char s[500010];
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &T);
  scanf("%s", s);
  T--;
  if (s[0] == 'w') {
    T -= b;
  }
  if (T >= 0) {
    ans = 1;
    sum[0] = 0;
    for (int i = 1; i < n; i++) {
      sum[i] = sum[i - 1] + a + (s[i] == 'w' ? b : 0) + 1;
      if (sum[i] <= T) ans = i + 1;
    }
    for (int i = 1; i < n; i++) {
      T -= a + 1 + (s[n - i] == 'w' ? b : 0);
      if (T < 0)
        break;
      else
        ans = max(ans, i + 1);
      int l = 0, r = n - i;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (T >= sum[mid] + min(i, l) * a)
          l = mid + 1;
        else
          r = mid;
      }
      l--;
      ans = max(ans, i + 1 + l);
    }
  } else
    ans = 0;
  printf("%d\n", ans);
  return 0;
}
