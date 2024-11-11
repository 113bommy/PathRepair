#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
const int inf = 1000000000;
const double pi = 2 * acos(0.0);
const double EPS = 1e-9;
int n, u, r, a[100], b[100], k[100], p[100], pp[100], aa[100];
long long ans;
void go(int move, int last) {
  if (move % 2 != u % 2) {
    long long cur = 0;
    for (int i = 1; i <= n; ++i) cur += (long long)a[i] * k[i];
    ans = max(ans, cur);
  }
  if (move == u + 1) return;
  if (last != 1) {
    for (int i = 1; i <= n; ++i) a[i] = (a[i] ^ b[i]);
    go(move + 1, 1);
    for (int i = 1; i <= n; ++i) a[i] = (a[i] ^ b[i]);
  }
  for (int i = 1; i <= n; ++i) aa[i] = a[i];
  for (int i = 1; i <= n; ++i) a[i] = aa[p[i]] + r;
  go(move + 1, 2);
  for (int i = 1; i <= n; ++i) aa[i] = a[i];
  for (int i = 1; i <= n; ++i) a[p[i]] = aa[i] - r;
  return;
}
int main() {
  cin >> n >> u >> r;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= n; ++i) cin >> k[i];
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 1; i <= n; ++i) pp[p[i]] = i;
  ans = -inf * (long long)inf;
  go(1, -1);
  cout << ans << endl;
  return 0;
}
