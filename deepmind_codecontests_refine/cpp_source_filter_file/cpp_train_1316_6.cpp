#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 9;
const int INF = 1e9 + 9;
vector<int> l;
vector<int> e;
int main() {
  int n, m, cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;
  for (int i = 0; i < cl; i++) {
    int a;
    cin >> a;
    a--;
    e.push_back(a);
  }
  for (int j = 0; j < ce; j++) {
    int a;
    cin >> a;
    a--;
    l.push_back(a);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    int ans = INF;
    if (x1 == x2) {
      cout << abs(x1 - x2) << '\n';
      continue;
    }
    int pos_l1 = upper_bound(l.begin(), l.end(), y1) - l.begin();
    int pos_l2 = upper_bound(l.begin(), l.end(), y2) - l.begin();
    int pos_e1 = upper_bound(e.begin(), e.end(), y1) - e.begin();
    int pos_e2 = upper_bound(e.begin(), e.end(), y2) - e.begin();
    if (pos_l1 != 0) {
      int t = abs(x1 - x2) / v;
      if (abs(x1 - x2) % v != 0) {
        t++;
      }
      int now = abs(y1 - l[pos_l1 - 1]) + abs(y2 - l[pos_l1 - 1]) + t;
      ans = min(ans, now);
    }
    if (pos_l2 != 0) {
      int t = abs(x1 - x2) / v;
      if (abs(x1 - x2) % v != 0) {
        t++;
      }
      int now = abs(y1 - l[pos_l2 - 1]) + abs(y2 - l[pos_l2 - 1]) + t;
      ans = min(ans, now);
    }
    if (pos_l1 != (int)l.size()) {
      int t = abs(x1 - x2) / v;
      if (abs(x1 - x2) % v != 0) {
        t++;
      }
      int now = abs(y1 - l[pos_l1]) + abs(y2 - l[pos_l1]) + t;
      ans = min(ans, now);
    }
    if (pos_l2 != (int)l.size()) {
      int t = abs(x1 - x2) / v;
      if (abs(x1 - x2) % v != 0) {
        t++;
      }
      int now = abs(y1 - l[pos_l2]) + abs(y2 - l[pos_l2]) + t;
      ans = min(ans, now);
    }
    if (pos_e1 != 0) {
      int now =
          abs(y1 - e[pos_e1 - 1]) + abs(y2 - e[pos_e1 - 1]) + abs(x1 - x2);
      ans = min(ans, now);
    }
    if (pos_e1 != (int)e.size()) {
      int now = abs(y1 - e[pos_e1]) + abs(y2 - e[pos_e1]) + abs(x1 - x2);
      ans = min(ans, now);
    }
    if (pos_e2 != 0) {
      int now =
          abs(y1 - e[pos_e2 - 1]) + abs(y2 - e[pos_e2 - 1]) + abs(x1 - x2);
      ans = min(ans, now);
    }
    if (pos_e2 != (int)e.size()) {
      int now = abs(y1 - e[pos_e2]) + abs(y2 - e[pos_e2]) + abs(x1 - x2);
      ans = min(ans, now);
    }
    cout << ans << '\n';
  }
  return 0;
}
