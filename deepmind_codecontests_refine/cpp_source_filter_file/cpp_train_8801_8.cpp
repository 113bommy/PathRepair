#include <bits/stdc++.h>
using namespace std;
long long n, m, k, c[105], ar[105][105], mem[104][104][104];
long long solve(long long i, long long jojo, long long kkk) {
  long long &re = mem[i][jojo][kkk];
  if (mem[i][jojo][kkk] != -1) return re;
  if (kkk > k) return 1e16;
  if (i >= n && kkk == k) return 0;
  if (i >= n) return 1e16;
  long long mi = 1e16;
  for (int j = 0; j < m; j++) {
    long long c1 = 1e16;
    if (c[i] == 0) {
      if (jojo != j) {
        c1 = solve(i + 1, j, kkk + 1) + ar[i][j];
      } else
        c1 = solve(i + 1, j, kkk) + ar[i][j];
    } else if (c[i] - 1 == jojo)
      c1 = solve(i + 1, c[i] - 1, kkk);
    else
      c1 = solve(i + 1, c[i] - 1, kkk + 1);
    mi = min(mi, c1);
  }
  return re = mi;
}
int main() {
  memset(mem, -1, sizeof mem);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> ar[i][j];
  long long ans = solve(0, 0, 0);
  if (ans == 1e16)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
