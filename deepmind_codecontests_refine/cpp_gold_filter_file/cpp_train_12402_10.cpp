#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ar[n + 1];
  long long pre[n + 1];
  for (int i = 1; i <= n; i++) cin >> ar[i];
  pre[0] = 0;
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ ar[i];
  if (pre[n] == 0) {
    std::cout << -1 << '\n';
    return 0;
  }
  int cur = 1;
  for (int idx = 30; idx >= 0; idx--) {
    int flag = 0;
    for (int i = cur; i <= n; i++)
      if (pre[i] & 1 << idx) {
        swap(pre[i], pre[cur]);
        break;
      }
    if (pre[cur] & 1 << idx) {
      for (int i = 1; i <= n; i++) {
        if (cur == i) continue;
        if (pre[i] & 1 << idx) pre[i] ^= pre[cur];
      }
      cur++;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (pre[i] > 0) ans++;
  std::cout << ans << '\n';
  return 0;
}
