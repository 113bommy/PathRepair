#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> pos(n + m, 0);
  vector<long long> flag(n + m, 0);
  vector<long long> ans(m, 0);
  for (long long i = 0; i < n + m; i++) cin >> pos[i];
  for (long long i = 0; i < n + m; i++) cin >> flag[i];
  long long an = 0, ff = 0;
  long long index = 0;
  long long x = 0;
  long long l = -1;
  vector<long long> foo;
  long long j = 0;
  for (j = 0; j < n + m; j++)
    if (flag[j] == 0)
      ans[0]++;
    else
      break;
  for (long long i = j; i < n + m; i++) {
    if (flag[i] == 0) foo.push_back(pos[i]);
    if (flag[i] == 1 && x == 0) {
      l = pos[i];
      x = x + 1;
    } else if (flag[i] == 1 && x == 1) {
      long long mi = (l + pos[i]) >> 1;
      ans[index] += upper_bound(foo.begin(), foo.end(), mi) - foo.begin();
      index++;
      ans[index] +=
          foo.size() - (upper_bound(foo.begin(), foo.end(), mi) - foo.begin());
      x = 1;
      l = pos[i];
      foo.clear();
    }
  }
  for (long long i = n + m - 1; i >= 0; i--)
    if (flag[i] == 0) {
      ans[m - 1]++;
    } else
      break;
  for (long long i = 0; i < m; i++) cout << ans[i] << " \n"[i == m - 1];
  return 0;
}
