#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;
string alp = "abcdefghijklmnopqrstuvwxyz";
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long test = 1;
  while (test--) {
    long long n;
    cin >> n;
    vector<pair<long long, pair<long long, long long>>> v, u;
    for (long long i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      v.push_back(make_pair(y, make_pair(x, i + 1)));
    }
    sort(v.rbegin(), v.rend());
    map<long long, priority_queue<pair<long long, long long>>> m;
    for (long long i = 0; i < n; i++) {
      m[v[i].first].push(make_pair(v[i].second.first, v[i].second.second));
    }
    for (long long i = n - 1; i >= 0; i--) {
      v[i].second.first = m[v[i].first].top().first;
      v[i].second.second = m[v[i].first].top().second;
      m[v[i].first].pop();
    }
    long long k, tot = 0;
    cin >> k;
    vector<pair<long long, long long>> r, ans;
    for (long long i = 0; i < k; i++) {
      long long x;
      cin >> x;
      r.push_back(make_pair(x, i + 1));
    }
    map<long long, long long> m1;
    sort(r.begin(), r.end());
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < k; j++) {
        if (r[j].first >= v[i].second.first && m1[j] == 0) {
          tot += v[i].first;
          ans.push_back(make_pair(v[i].second.second, r[j].second));
          m1[j] = 1;
          break;
        }
      }
    }
    cout << ans.size() << " " << tot << "\n";
    for (long long i = 0; i < ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << "\n";
    }
  }
}
