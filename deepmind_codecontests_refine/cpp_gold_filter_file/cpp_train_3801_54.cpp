#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, val, i, j, k, n, m, val2;
  vector<pair<long long, long long> > ans;
  cin >> x;
  for (n = 1; n <= (3000000); n++) {
    val = x;
    val -= (n - 1) * n * (2 * n - 1) / 6;
    val += n * n * (n - 1) / 2;
    val2 = n * n - ((n - 1) * n) / 2;
    if (val % val2 == 0) {
      val2 = val / val2;
      if (val2 >= n) {
        ans.push_back(make_pair(n, val2));
        if (n != val2) ans.push_back(make_pair(val2, n));
      }
    }
  }
  printf("%d\n", ans.size());
  sort(ans.begin(), ans.end());
  for (i = 0; i < ans.size(); i++)
    printf("%lld %lld\n", ans[i].first, ans[i].second);
  return 0;
}
