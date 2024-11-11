#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
void run() {
  long long n, rr, c, first, second;
  long long t;
  cin >> t;
  for (long long k = 0; k < t; ++k) {
    cin >> n;
    vector<pair<long long, long long> > ans;
    for (long long i = 0; i < n; ++i) {
      cin >> first >> second;
      ans.push_back(make_pair(first, -1));
      ans.push_back(make_pair(second, 1));
    }
    sort(ans.begin(), ans.end());
    long long i = 0;
    long long j = 2 * n - 1;
    while (ans[i].second != 1) ++i;
    while (ans[j].second != -1) --j;
    if (n == 1)
      cout << 0 << endl;
    else
      cout << (long long)abs(ans[j].first - ans[i].first) << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  run();
  long long pause;
  cin >> pause;
}
