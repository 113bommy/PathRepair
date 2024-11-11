#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[5010];
  while (cin >> n) {
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) continue;
      for (int j = 2; j * j < abs(a[i]); j++) {
        while (a[i] % (j * j) == 0) a[i] /= (j * j);
      }
    }
    int ans[5010];
    int pre[5010];
    memset(ans, 0, sizeof(ans));
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
      pre[i] = m[a[i]];
      m[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
      int t = 0;
      for (int j = i; j <= n; j++) {
        if (a[j] && pre[j] < i) t++;
        ans[max(1, t)]++;
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
