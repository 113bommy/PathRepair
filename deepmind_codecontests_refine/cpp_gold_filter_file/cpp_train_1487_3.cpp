#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n;
    vector<long long> a(n + 1);
    map<long long, vector<long long>> mp;
    map<long long, set<long long>> ans;
    for (long long i = 1; i <= n; ++i) {
      cin >> a[i];
      mp[a[i]].push_back(i);
    }
    for (auto it : mp) {
      long long maxx = it.second[0];
      for (long long i = 1; i < it.second.size(); ++i) {
        long long diff = it.second[i] - it.second[i - 1];
        maxx = max(maxx, diff);
      }
      long long diff = n - it.second.back() + 1;
      maxx = max(maxx, diff);
      ans[maxx].insert(it.first);
    }
    long long minn = LLONG_MAX;
    for (long long i = 1; i <= n; ++i) {
      if (ans[i].empty()) {
        if (minn == LLONG_MAX)
          cout << -1;
        else
          cout << minn;
      } else {
        minn = min(minn, *(ans[i].begin()));
        cout << minn;
      }
      cout << " ";
    }
    cout << '\n';
  }
}
