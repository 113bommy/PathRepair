#include <bits/stdc++.h>
using namespace std;
long long to[1010], pre[1010], val[1010];
long long ans[1010][3], cnt = 0;
int main() {
  long long n, m;
  int cas = 0;
  cin >> n >> m;
  cnt = 0;
  memset(to, 0, sizeof to);
  memset(pre, 0, sizeof pre);
  memset(val, 0, sizeof val);
  memset(ans, 0, sizeof ans);
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u;
    cin >> to[u] >> val[u];
    pre[to[u]] = u;
  }
  if (n == m) {
    cout << "0" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (to[i] && !pre[i]) {
      int tmp = i;
      long long mi = 0xfffffffffffffff;
      while (to[tmp]) {
        mi = min(mi, val[tmp]);
        tmp = to[tmp];
      }
      ans[cnt][0] = i;
      ans[cnt][1] = tmp;
      ans[cnt][2] = mi;
      cnt++;
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  }
}
