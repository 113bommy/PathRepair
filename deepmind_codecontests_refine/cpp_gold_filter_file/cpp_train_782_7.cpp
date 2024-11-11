#include <bits/stdc++.h>
using namespace std;
long long p3(long long x) { return x * x * x; }
pair<long long, long long> ans;
void solve(long long m, long long steps, long long sum) {
  if (m == 0) {
    ans = max(ans, {steps, sum});
    return;
  }
  long long x = 1;
  while (p3(x + 1) <= m) x++;
  solve(m - p3(x), steps + 1, sum + p3(x));
  if (x - 1 >= 0) solve(p3(x) - 1 - p3(x - 1), steps + 1, sum + p3(x - 1));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long m;
  cin >> m;
  solve(m, 0, 0);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
