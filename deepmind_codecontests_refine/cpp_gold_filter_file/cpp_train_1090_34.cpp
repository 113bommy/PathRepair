#include <bits/stdc++.h>
using namespace std;
long long h, n;
long long solve(long long l, long long r, int p) {
  if (l == r) return 0;
  long long m = (l + r) / 2;
  long long sol = 0;
  if (n <= m) {
    if (p == 0)
      sol = solve(l, m, 1 - p);
    else
      sol = solve(l, m, p) + (r - l);
  } else {
    if (p == 1)
      sol = solve(m + 1, r, 1 - p);
    else
      sol = solve(m + 1, r, p) + (r - l);
  }
  sol += 1;
  return sol;
}
int main() {
  cin >> h >> n;
  cout << solve(1, 1LL << h, 0) << endl;
}
