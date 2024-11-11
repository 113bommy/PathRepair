#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, rb, cb, rd, cd;
  scanf("%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd);
  int ans = 0;
  int dr = 1, dc = 1;
  while (rb != rd && cb != cd) {
    if (rb + dr < 1 || rb + dr > n) dr *= -1;
    if (cb + dc < 1 || cb + dc > m) dc *= -1;
    rb += dr;
    cb += dc;
    ans++;
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
