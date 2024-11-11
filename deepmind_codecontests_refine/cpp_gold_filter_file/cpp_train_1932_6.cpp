#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, q, t, x;
int when[N];
vector<pair<int, int> > notif;
map<int, int> app;
int max_t = 0;
int main() {
  cin >> n >> q;
  for (int i = 0; i <= n; ++i) when[i] = -1;
  int ans = 0;
  for (int i = 0; i < q; ++i) {
    cin >> t >> x;
    if (t == 1) {
      app[x]++;
      ans++;
      notif.push_back(make_pair(i, x));
    } else if (t == 2) {
      ans -= app[x];
      when[x] = i;
      app[x] = 0;
    } else {
      for (; max_t < x; ++max_t) {
        int happend = notif[max_t].first, app_i = notif[max_t].second;
        if (app_i != -1 && happend > when[app_i]) {
          app[app_i]--;
          notif[max_t].second = -1;
          ans--;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
