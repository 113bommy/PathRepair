#include <bits/stdc++.h>
using namespace std;
const long long init = 1e9 + 7;
const long long N = 2e5 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> counts(N, 0), counts1(N, 0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) counts[i] = 0, counts1[i] = 0;
    for (int i = 0; i < n; ++i) {
      int t, type;
      cin >> t >> type;
      ++counts[t];
      if (type == 1) ++counts1[t];
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
      if (counts[i] > 0) {
        v.push_back(counts[i]);
      }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    set<int> s;
    s.insert(v[0]);
    int sum = v[0];
    for (int i = 1; i < v.size(); ++i) {
      int y = *(s.begin());
      int z = min(y - 1, v[i]);
      if (z < 1) break;
      s.insert(z);
      sum += z;
    }
    priority_queue<pair<int, int> > temps;
    priority_queue<int> nums;
    for (int i = 1; i <= n; ++i) {
      if (counts[i] > 0) temps.push(make_pair(counts[i], counts1[i]));
    }
    int sum2 = 0;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      int z = (*it);
      if (!temps.empty()) {
        pair<int, int> pt = temps.top();
        while (pt.first >= z) {
          nums.push(pt.second);
          temps.pop();
          if (temps.empty()) break;
          pt = temps.top();
        }
      }
      sum2 += min(z, nums.top());
      nums.pop();
    }
    cout << sum << " " << sum2 << endl;
  }
  return 0;
}
