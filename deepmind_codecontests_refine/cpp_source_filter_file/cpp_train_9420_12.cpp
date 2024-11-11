#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> l(n, 0), d(n, 0), suf(n + 1, 0);
  vector<pair<int, int>> kaki;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    mp[l[i]]++;
  }
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    kaki.push_back({l[i], d});
  }
  sort(kaki.begin(), kaki.end());
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + kaki[i].second;
  }
  int ans = 1e9;
  set<int> se;
  int idx = 0;
  for (auto i : mp) {
    int sz = i.second;
    int pos = lower_bound(kaki.begin(), kaki.end(), make_pair(i.first, 0)) -
              kaki.begin();
    int temp = suf[pos + sz];
    for (; idx < pos; idx++) {
      se.insert(-kaki[idx].second);
    }
    int pref;
    if (pos < sz) {
      pref = 0;
    } else {
      pref = suf[0] - suf[pos];
      int banyak = sz - 1;
      for (auto it = se.begin(); it != se.end(); ++it) {
        if (banyak == 0) break;
        pref += (*it);
        banyak--;
      }
    }
    ans = min(ans, temp + pref);
  }
  cout << ans;
}
