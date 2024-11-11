#include <bits/stdc++.h>
using namespace std;
const int len = 1e5 + 5;
long long arr[len];
char tp[len];
int main() {
  int n;
  long long grass = 0, water = 0, can = 0, ans = 0, cur = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  scanf("%s", tp);
  for (int i = 0; i < n; i++) {
    cur -= arr[i];
    ans += arr[i];
    if (tp[i] == 'G') grass += 2 * arr[i];
    if (tp[i] == 'W') water += 2 * arr[i], can = 1;
    if (cur < 0) {
      long long mn = min(-cur, water);
      cur += mn;
      water -= mn;
      ans += mn;
      mn = min(-cur, grass);
      cur += mn;
      grass -= mn;
      ans += 2 * mn;
      if (can) {
        ans += -3 * cur;
        cur = 0;
      } else {
        ans += -5 * cur;
        cur = 0;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
