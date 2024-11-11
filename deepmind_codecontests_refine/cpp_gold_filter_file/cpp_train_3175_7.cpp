#include <bits/stdc++.h>
using namespace std;
int res = 1e9;
int n, a[100005], start, trace[100005], gt[100005], f[100005];
void bru(int x, int val) {
  if (x < 1) return;
  if (x > 1e5) return;
  if (trace[x] == start) return;
  trace[x] = start;
  f[x] += 1;
  gt[x] += val;
  bru(x * 2, val + 1);
  bru(x / 2, val + 1);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    start = i;
    bru(a[i], 0);
  }
  for (int i = 1; i <= 1e5; ++i)
    if (f[i] == n) res = min(res, gt[i]);
  cout << res;
  return 0;
}
