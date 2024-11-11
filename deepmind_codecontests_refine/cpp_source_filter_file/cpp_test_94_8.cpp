#include <bits/stdc++.h>
using namespace std;
long long a[15], n, k, t;
vector<long long> ans;
long long ten[] = {1,       10,       100,       1000,       10000,      100000,
                   1000000, 10000000, 100000000, 1000000000, 10000000000};
signed main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    k++;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    ans.clear();
    for (long long i = 1; i <= n; i++)
      if (i < n) {
        long long d = a[i + 1] - a[i];
        if (k < ten[d] - 1) {
          ans.push_back(k);
          break;
        } else {
          ans.push_back(ten[d] - 1);
          k -= ten[d] - 1;
        }
      } else if (i == n)
        ans.push_back(k);
    for (long long i = ans.size() - 1; i >= 0; i--) printf("%lld", ans[i]);
    putchar('\n');
  }
}
