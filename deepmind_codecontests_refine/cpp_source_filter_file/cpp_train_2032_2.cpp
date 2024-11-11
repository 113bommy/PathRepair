#include <bits/stdc++.h>
using namespace std;
const int Z = (int)2e3 + 111;
const int inf = (int)1e9 + 111;
const long long llinf = (long long)1e18 + 5;
const int MOD = (int)1e9 + 7;
long long a[Z], b[Z];
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  int n;
  long long sum1 = 0, sum2 = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum1 += a[i];
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    sum2 += b[i];
  }
  long long val = abs(sum1 - sum2);
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (abs(sum1 - 2 * a[i] + 2 * b[j] - sum2) < val) {
        val = abs(sum1 - 2 * a[i] + 2 * b[j] - sum2);
        ans.clear();
        ans.push_back(i);
        ans.push_back(j);
      }
    }
  }
  set<pair<long double, pair<int, int> > > mn;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      mn.insert(make_pair(a[i] + a[j], make_pair(i, j)));
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      long long y = b[i] + b[j];
      long double cur = (long double)abs(sum1 + 2 * y - sum2) / 2;
      auto it = mn.lower_bound(make_pair(cur, make_pair(-1, -1)));
      if (it != mn.end()) {
        if ((it->first - cur) * 2 < val) {
          val = (it->first - cur) * 2;
          ans.clear();
          ans.push_back((it->second).first);
          ans.push_back(i);
          ans.push_back((it->second).second);
          ans.push_back(j);
        }
      }
      if (it != mn.begin()) {
        it--;
        if ((cur - it->first) * 2 < val) {
          val = (cur - it->first) * 2;
          ans.clear();
          ans.push_back((it->second).first);
          ans.push_back(i);
          ans.push_back((it->second).second);
          ans.push_back(j);
        }
      }
    }
  }
  cout << val << '\n';
  cout << (int)ans.size() / 2 << '\n';
  for (int i = 0; i < (int)ans.size(); i += 2) {
    cout << ans[i] << ' ' << ans[i + 1] << '\n';
  }
  return 0;
}
