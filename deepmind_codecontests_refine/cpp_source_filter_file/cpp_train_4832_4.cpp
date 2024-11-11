#include <bits/stdc++.h>
using namespace std;
void precompute(void) {}
int cum[1 << 22], num[1 << 20];
int low, high, n, k, mini, maxi, ans, flag;
int main() {
  precompute();
  while (cin >> n >> k) {
    memset(cum, 0, sizeof(cum));
    for (int i = 0; i < n; i++) {
      cin >> num[i];
      if (num[i] >= k) {
        cum[num[i] - k]++;
      }
    }
    ans = k;
    mini = *(min_element(num, num + n));
    maxi = *(max_element(num, num + n));
    if (mini <= ans) {
      cout << mini << endl;
      continue;
    }
    for (int i = 1; i <= (1 << 20); i++) {
      cum[i] += cum[i - 1];
    }
    ans = k + 1;
    for (int x = k + 2; x <= maxi; x++) {
      low = 0;
      high = x - k - 1;
      flag = 1;
      while (low <= maxi) {
        if (cum[high] - cum[low] != 0) {
          flag = 0;
          break;
        }
        low += x;
        high += x;
      }
      if (flag) ans = x;
    }
    cout << ans << endl;
  }
  return 0;
}
