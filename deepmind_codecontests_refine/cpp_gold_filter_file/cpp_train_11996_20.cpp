#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long tmp = n / 2;
  if ((n % 2 and tmp * tmp < m) or (n % 2 == 0 and tmp * (tmp - 1) < m)) {
    cout << "-1\n";
    return 0;
  }
  vector<long long> ans;
  long long last = 1;
  for (long long i = 3; i <= n; i++) {
    long long tmp = i / 2;
    if (m == 0) {
      break;
    }
    if (i % 2 and tmp * tmp >= m) {
      for (long long j = 1; j < i; j++) ans.push_back(j);
      long long req = m - (tmp - 1) * tmp;
      ans.push_back(ans.back() + ans[ans.size() - 2 * req]);
      last = ans.back() + 2;
      break;
    } else if (tmp * (tmp - 1) >= m) {
      for (long long j = 1; j < i; j++) ans.push_back(j);
      long long req = m - (tmp - 1) * (tmp - 1);
      ans.push_back(ans.back() + ans[ans.size() - 2 * req]);
      last = ans.back() + 2;
      break;
    }
  }
  long long mx = 1e8;
  ans.push_back(mx);
  while (ans.size() != 5001) {
    ans.push_back(ans.back() + last);
  }
  for (long long i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
}
