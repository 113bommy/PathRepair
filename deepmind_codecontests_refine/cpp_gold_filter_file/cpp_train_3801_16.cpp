#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  vector<pair<long long, long long> > ans;
  cin >> x;
  long long p = cbrt(6 * x) + 2, n, m;
  for (m = 1; m <= p; m++) {
    long long a = (6 * x + m * (m * m - 1)), b = (3 * m * (m + 1));
    if (a % b == 0) {
      n = a / b;
      if (m > n)
        break;
      else
        ans.push_back({m, n});
    }
  }
  int num = 2 * ans.size(), flag = 0;
  if (ans[ans.size() - 1].first == ans[ans.size() - 1].second)
    num -= 1, flag = 1;
  printf("%d\n", num);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
  for (int i = ans.size() - 1 - flag; i >= 0; i--) {
    cout << ans[i].second << " " << ans[i].first << "\n";
  }
  return 0;
}
