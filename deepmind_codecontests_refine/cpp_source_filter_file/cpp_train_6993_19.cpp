#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
long long n, m, i, j, k, q, p, a[N], u, v, qanak[N], aj[N], dzax[N], ma;
vector<pair<long long, pair<long long, long long> > > x, ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
    qanak[a[i]]++;
    if (qanak[a[i]] == 1) aj[a[i]] = i;
    dzax[a[i]] = i;
  }
  for (i = 1; i <= ma; i++) {
    if (qanak[i] != 0)
      x.push_back(make_pair(aj[i], make_pair(dzax[i], qanak[i])));
  }
  sort(x.begin(), x.end());
  for (i = 0; i < x.size(); i++) {
    if (v < x[i].first) {
      ans.push_back(make_pair(u, make_pair(v, p)));
      u = x[i].first;
      v = x[i].second.first;
      p = x[i].second.second;
    } else {
      u = min(u, x[i].first);
      v = max(v, x[i].second.first);
      p = max(p, x[i].second.second);
    }
  }
  ans.push_back(make_pair(u, make_pair(v, p)));
  for (i = 0; i < ans.size(); i++) {
    k += ans[i].second.first - ans[i].first + 1 - ans[i].second.second;
  }
  cout << k << endl;
  return 0;
}
