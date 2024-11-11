#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  vector<pair<string, long long>> t;
  vector<long long> q(n);
  vector<long long> mx(n + 1, -1);
  long long cur = 0;
  long long cnt = 0;
  for (long long i = 0; i < (long long)(2 * n); i++) {
    string s;
    cin >> s;
    if (s == "+") {
      cur++;
      cnt++;
      t.push_back({s, 0});
    } else {
      cnt--;
      long long x;
      cin >> x;
      x--;
      q[x] = cur;
      if (mx[cur] > x || cnt < 0) {
        cout << "NO" << endl;
        return 0;
      }
      t.push_back({s, x});
      mx[cur] = x;
    }
  }
  set<long long> ind;
  for (long long i = 0; i < (long long)(n); i++) {
    ind.insert(i);
  }
  vector<long long> ans(n);
  for (long long i = 0; i < (long long)(n); i++) {
    auto it = ind.lower_bound(q[i]);
    it--;
    ans[*it] = i;
    ind.erase(it);
  }
  cur = 0;
  for (long long i = 0; i < (long long)(2 * n); i++) {
    if (t[i].first == "+") {
      ind.insert(ans[i]);
      cur++;
    } else {
      if (*ind.begin() != t[i].second) {
        cout << "NO" << endl;
        return 0;
      }
      ind.erase(ind.begin());
    }
  }
  cout << "YES" << endl;
  for (long long i = 0; i < (long long)(n); i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
}
