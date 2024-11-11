#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, T;
int d[N], cnt;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    vector<pair<int, int> > segs;
    for (int i = 1; i <= n; i++) {
      int l, r;
      cin >> l >> r;
      segs.push_back({l, -i});
      segs.push_back({r, i});
    }
    sort(segs.begin(), segs.end());
    set<int> s;
    cnt = 0;
    memset(d, 0, sizeof d);
    for (int i = 0; i < segs.size(); i++) {
      if (segs[i].second < 0)
        s.insert(-segs[i].second);
      else
        s.erase(s.find(segs[i].second));
      if (s.empty()) cnt++;
      if (s.size() == 1 && segs[i].second > 0 && segs[i + 1].second < 0 &&
          segs[i + 1].first > segs[i].first)
        d[*s.begin()]++;
      if (s.size() == 1 && segs[i].second < 0 && segs[i + 1].second > 0)
        d[*s.begin()]--;
    }
    int maxd = -n;
    for (int i = 1; i <= n; i++) maxd = max(maxd, d[i]);
    cout << cnt + maxd << endl;
  }
  return 0;
}
