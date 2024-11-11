#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, i;
  scanf("%d %d", &n, &x);
  int a[n + 1], mx[n + 1];
  vector<int> pos[x + 1];
  int far[x + 1], close[x + 2];
  mx[0] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]].push_back(i);
    mx[i] = max(mx[i - 1], a[i]);
  }
  far[0] = 0;
  for (i = 1; i <= x; i++) {
    if (pos[i].empty() == 1)
      far[i] = far[i - 1];
    else
      far[i] = max(far[i - 1], pos[i].back());
  }
  close[x + 1] = n + 1;
  for (i = x; i > 0; i--) {
    if (pos[i].empty() == 1)
      close[i] = close[i + 1];
    else
      close[i] = min(close[i + 1], pos[i][0]);
  }
  int max_l, max_r;
  for (i = 1; i <= x; i++) {
    if (pos[i].empty() == 0) {
      if (pos[i][0] < far[i - 1]) {
        break;
      }
    }
  }
  max_l = i - 1;
  for (i = x; i >= 0; i--) {
    if (pos[i].empty() == 0) {
      if (pos[i].back() > close[i + 1]) {
        break;
      }
    }
  }
  max_r = i + 1;
  if (max_l > max_r) {
    printf("%lld", 1ll * x * (x + 1) / 2);
    return 0;
  }
  long long int ans = max_l + x - max_r + 2;
  for (i = 1; i <= max_l; i++) {
    int cur_r = mx[far[i]] + 1;
    cur_r = max(cur_r, max_r);
    ans = ans + x - cur_r + 1;
  }
  printf("%lld", ans);
}
