#include <bits/stdc++.h>
using namespace std;
void run();
int main() {
  ios::sync_with_stdio(0);
  run();
}
struct seg_t {
  long long x0, x1, y;
  bool operator<(seg_t const &other) const {
    return y < other.y or y == other.y and x1 > other.x1;
  }
};
bool byx(seg_t const &a, seg_t const &b) {
  return a.x0 < b.x0 or a.x0 == b.x0 and a.y < b.y;
}
seg_t seg[100000];
pair<long long, long long> evt[200000];
void run() {
  int m, n;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> seg[i].x0 >> seg[i].x1 >> seg[i].y;
  vector<seg_t> profile;
  {
    static pair<long long, long long> evt[200000];
    for (int i = 0; i < n; i++)
      evt[i * 2 + 0] = {seg[i].x0, i}, evt[i * 2 + 1] = {seg[i].x1, ~i};
    sort(evt, evt + 2 * n);
    set<seg_t> active;
    for (int i = 0; i < n * 2; i++) {
      if (evt[i].second >= 0) {
        active.insert(seg[evt[i].second]);
      } else {
        active.erase(seg[~evt[i].second]);
      }
      if (i + 1 == n * 2 or evt[i + 1].first > evt[i].first) {
        if (active.empty()) {
          if (not profile.empty())
            profile.back().x1 = min(profile.back().x1, evt[i].first);
        } else {
          seg_t state = {evt[i].first, active.begin()->x1, active.begin()->y};
          if (not profile.empty() and state.x0 <= profile.back().x1 and
              profile.back().y == state.y) {
            profile.back().x1 = max(profile.back().x1, state.x1);
          } else {
            if (not profile.empty())
              profile.back().x1 = min(profile.back().x1, evt[i].first);
            profile.push_back(state);
          }
        }
      }
    }
  }
  int const evts = profile.size() * 2;
  for (int i = 0; i < profile.size(); i++)
    evt[i] = {profile[i].y - profile[i].x1, +1};
  for (int i = 0; i < profile.size(); i++)
    evt[i + profile.size()] = {profile[i].y - profile[i].x0, -1};
  sort(evt, evt + evts);
  long long cad = 0, mad = 0;
  while (m--) {
    long long x;
    cin >> x;
    static long long id;
    while (id < evts and evt[id].first <= x) {
      mad += evt[id].second;
      cad -= evt[id].second * evt[id].first;
      ++id;
    }
    cout << cad + mad * x << endl;
  }
}
