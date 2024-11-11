#include <bits/stdc++.h>
using namespace std;
int n, m;
set<pair<int, int> > vp;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  if (n == 0) {
    cout << 0 << ' ' << 1 << endl;
    cout << 0 << ' ' << m << endl;
    cout << 0 << ' ' << 0 << endl;
    cout << 0 << ' ' << m - 1 << endl;
    return 0;
  } else if (m == 0) {
    cout << 1 << ' ' << 0 << endl;
    cout << n << ' ' << 0 << endl;
    cout << 0 << ' ' << 0 << endl;
    cout << n - 1 << ' ' << 0 << endl;
    return 0;
  }
  vp.insert(make_pair(n, m));
  vp.insert(make_pair(0, 0));
  vp.insert(make_pair(0, m));
  vp.insert(make_pair(n, 0));
  vp.insert(make_pair(n - 1, m - 1));
  vp.insert(make_pair(1, 1));
  vp.insert(make_pair(n - 1, 1));
  vp.insert(make_pair(m - 1, 1));
  vp.insert(make_pair(n - 1, m));
  vp.insert(make_pair(n, m - 1));
  vp.insert(make_pair(0, 1));
  vp.insert(make_pair(1, 0));
  vector<pair<int, int> > num;
  pair<int, int> ans[4];
  double maxi = 0.;
  for (set<pair<int, int> >::iterator x = vp.begin(); x != vp.end(); ++x) {
    for (set<pair<int, int> >::iterator y = vp.begin(); y != vp.end(); ++y) {
      if (y == x) continue;
      for (set<pair<int, int> >::iterator z = vp.begin(); z != vp.end(); ++z) {
        if (z == y || z == x) continue;
        for (set<pair<int, int> >::iterator t = vp.begin(); t != vp.end();
             ++t) {
          if (t == z || t == y || t == x) continue;
          pair<int, int> tmp[4];
          int arr[4] = {0, 1, 2, 3};
          tmp[0].first = x->first;
          tmp[0].second = x->second;
          tmp[1].first = y->first;
          tmp[1].second = y->second;
          tmp[2].first = z->first;
          tmp[2].second = z->second;
          tmp[3].first = t->first;
          tmp[3].second = t->second;
          double dis = 0.;
          do {
            double dis = 0.;
            dis +=
                sqrt((double)((tmp[arr[0]].first - tmp[arr[1]].first) *
                                  (tmp[arr[0]].first - tmp[arr[1]].first) +
                              (tmp[arr[0]].second - tmp[arr[1]].second) *
                                  (tmp[arr[0]].second - tmp[arr[1]].second)));
            dis +=
                sqrt((double)((tmp[arr[1]].first - tmp[arr[2]].first) *
                                  (tmp[arr[1]].first - tmp[arr[2]].first) +
                              (tmp[arr[1]].second - tmp[arr[2]].second) *
                                  (tmp[arr[1]].second - tmp[arr[2]].second)));
            dis +=
                sqrt((double)((tmp[arr[2]].first - tmp[arr[3]].first) *
                                  (tmp[arr[2]].first - tmp[arr[3]].first) +
                              (tmp[arr[2]].second - tmp[arr[3]].second) *
                                  (tmp[arr[2]].second - tmp[arr[3]].second)));
            if (dis > maxi) {
              maxi = dis;
              for (int i = 0; i < 4; i++) ans[i] = tmp[arr[i]];
            }
          } while (next_permutation(arr, arr + 4));
        }
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }
  return 0;
}
