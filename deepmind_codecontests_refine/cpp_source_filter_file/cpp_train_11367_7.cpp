#include <bits/stdc++.h>
using namespace std;
long long q, k;
long long getsl(int x, int opt) {
  long long sum = 0, add = 0, pw = 1, len = 0, cnt;
  while (1) {
    pw *= 10;
    len++;
    if (x > pw - 1) {
      cnt = pw - pw / 10;
      sum += add * cnt + cnt * (cnt + 1) / 2 * len;
      add += cnt * len;
    } else {
      cnt = x - pw / 10 + 1;
      sum += add * cnt + cnt * (cnt + 1) / 2 * len;
      add += cnt * len;
      break;
    }
  }
  return opt ? sum : add;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> k;
    int l = 1, r = 1e9, ans, mid;
    while (l <= r) {
      mid = l + r >> 1;
      if (getsl(mid, 1) < k)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    k -= getsl(ans, 1);
    l = 1, r = ans + 1;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (getsl(mid, 0) < k)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    k -= getsl(ans, 0);
    ans += 1;
    int t = ans, len = 0;
    while (t) t /= 10, len++;
    int rk = len - k + 1;
    while (rk != 1) ans /= 10, rk--;
    cout << ans % 10 << endl;
  }
  return 0;
}
