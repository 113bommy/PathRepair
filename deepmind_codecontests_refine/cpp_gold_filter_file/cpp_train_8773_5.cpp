#include <bits/stdc++.h>
using namespace std;
int read() {
  char x = getchar();
  int ans = 0, flag = 1;
  while (!isdigit(x))
    if (x == '-')
      flag = -1, x = getchar();
    else
      x = getchar();
  while (isdigit(x)) ans = ans * 10 + x - '0', x = getchar();
  return ans * flag;
}
int n, a[30005], sum[30005];
signed main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sum[n] = a[n];
    for (int i = n - 1; i >= 1; i--) sum[i] = min(sum[i + 1], a[i]);
    int pre = a[1];
    bool flag = 0;
    for (int i = 2; i < n; i++) {
      if (pre + sum[i + 1] < a[i]) {
        flag = 1;
        break;
      }
      if (pre < a[i]) {
        pre = min(min(pre, a[i]), a[i + 1] - (a[i] - pre));
      } else
        pre = min(pre, a[i]);
    }
    if (!flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
