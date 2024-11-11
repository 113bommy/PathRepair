#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct Fr {
  int t, a, b;
} fr[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, m, c, c0;
    cin >> n >> m >> c >> c0;
    for (int i = 0; i < n; i++) {
      cin >> fr[i].t >> fr[i].a >> fr[i].b;
    }
    sort(fr, fr + n, [](const Fr &a, const Fr &b) { return a.t < b.t; });
    vector<int> v = {0};
    for (int i = 0; i < n; i++) {
      v.push_back(fr[i].t);
    }
    v.push_back(m);
    map<int, long long> mp;
    mp[0] = c0;
    long long ans = 0, s = c0;
    bool ok = true;
    for (int i = 0, j = 0; i < v.size() - 1; i++) {
      while (j < n && fr[j].t == v[i]) {
        mp[fr[j].b] += fr[j].a;
        s += fr[j].a;
        j++;
      }
      while (s > c) {
        long long h = min(s - c, mp.rbegin()->second);
        s -= h;
        mp.rbegin()->second -= h;
        if (mp.rbegin()->second == 0) mp.erase(prev(mp.end()));
      }
      long long dist = v[i + 1] - v[i];
      while (!mp.empty() && dist > 0) {
        long long h = min(dist, mp.begin()->second);
        ans += h * mp.begin()->first;
        mp.begin()->second -= h;
        if (mp.begin()->second == 0) mp.erase(mp.begin());
        dist -= h;
        s -= h;
      }
      if (dist > 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << ans << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
