#include <bits/stdc++.h>
using namespace std;
const int MODP = 1000000007;
const int MAXN = 222;
long long n, x[MAXN], y[MAXN], sol[MAXN][MAXN];
long long ccw(int i, int j, int k) {
  return (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
}
long long solve(int l, int r) {
  if (l == r - 1) return 1;
  if (sol[l][r] != -1) return sol[l][r];
  sol[l][r] = 0;
  for (int i = l + 1; i < r; i++)
    if (ccw(r, l, i) > 0)
      sol[l][r] = (sol[l][r] + solve(l, i) * solve(i, r)) % MODP;
  return sol[l][r];
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  memset(sol, -1, sizeof sol);
  long long area = 0;
  for (int i = 0; i < n; i++)
    area += x[i] * y[((i + 1) % n)] - x[((i + 1) % n)] * y[i];
  if (area < 0) {
    reverse(x, x + n);
    reverse(y, y + n);
  }
  cout << solve(0, n - 1) << endl;
}
