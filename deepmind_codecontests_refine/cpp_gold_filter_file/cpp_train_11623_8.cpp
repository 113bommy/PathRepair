#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long a[4], i, ans[4] = {0};
  for (int i = 0; i < (4); i++) cin >> a[i];
  for (int i = 0; i < (2); i++) ans[i] = a[i] * 2;
  for (i = a[2]; i <= a[2] * 2; i++) {
    if (a[3] <= i && a[3] * 2 >= i && 2 * a[3] < ans[1]) {
      ans[2] = i;
      for (int i = 0; i < (3); i++) cout << ans[i] << endl;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
