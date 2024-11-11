#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
long long xx[N];
int k = 0;
void dfs(int x) {
  if (x > 10) return;
  for (int i = 0; i <= (1 << x) - 1; i++) {
    for (int j = 0; j < x; j++) {
      if ((i >> j) & 1) {
        xx[k] += 7 * (long long)pow(10, j);
      } else {
        xx[k] += 4 * (long long)pow(10, j);
      }
    }
    k++;
  }
  dfs(x + 1);
}
long long l, r;
int main() {
  dfs(1);
  cin >> l >> r;
  int p = lower_bound(xx, xx + k, l) - xx;
  long long ans = 0;
  sort(xx, xx + k);
  if (xx[p] == l) {
    ans += xx[p];
    l++;
    p++;
  }
  for (int i = p; l <= r; i++) {
    if (xx[i] <= r) {
      ans += (xx[i] - l + 1) * xx[i];
    } else {
      ans += (r - l + 1) * xx[i];
    }
    l = xx[i] + 1;
  }
  cout << ans << endl;
  return 0;
}
