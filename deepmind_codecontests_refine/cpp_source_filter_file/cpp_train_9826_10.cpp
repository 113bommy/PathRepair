#include <bits/stdc++.h>
using namespace std;
int res[1000005];
int cal(int n) {
  int res = 0;
  for (int i = 0;; i++) {
    if ((1 << i) > n) break;
    if ((1 << i) & n) continue;
    res |= (1 << i);
  }
  return res;
}
int main() {
  int n;
  while (cin >> n) {
    int ans = 0;
    memset(res, -1, sizeof(res));
    for (int i = n; i >= 0; i--) {
      if (res[i] != -1) continue;
      res[i] = cal(i);
      res[cal(i)] = i;
      ans += (i ^ cal(i)) << 1;
    }
    cout << ans << endl;
    for (int i = 0; i <= n; i++) printf("%d ", res[i]);
    puts("");
  }
  return 0;
}
