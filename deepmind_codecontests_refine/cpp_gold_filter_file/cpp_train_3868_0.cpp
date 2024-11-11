#include <bits/stdc++.h>
using namespace std;
long long n;
long long solve(long long x) {
  if (x == 0) return 1;
  if (x <= 9) return x;
  long long ans = 0;
  ans = solve(x / 10) * (x % 10);
  if (x >= 10) {
    ans = max(ans, 9 * solve(x / 10 - 1));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
