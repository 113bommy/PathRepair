#include <bits/stdc++.h>
using namespace std;
int n, dau[2 * 1000000 + 2], m;
void enter() {
  cin >> n;
  int k;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    dau[k] = k;
    m = max(m, k);
  }
  for (int i = 1; i <= 1000000; i++)
    if (dau[i] != i) dau[i] = dau[i - 1];
}
void solve() {
  int ans = 0;
  for (int i = 1; i <= 1000000; i++)
    if (dau[i] == i) {
      int x = 2 * i;
      while (x <= m * 2) {
        ans = max(ans, dau[x - 1] % i);
        x += i;
      }
    }
  cout << ans;
}
int main() {
  enter();
  solve();
  return 0;
}
