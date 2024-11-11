#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const LL LLINF = 1e14;
const double pi = acos(-1.0);
vector<int> c, l;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, cl, cc, v;
  cin >> n >> m >> cl >> cc >> v;
  for (int i = 1; i <= cl; i++) {
    int x;
    cin >> x;
    l.push_back(x);
  }
  for (int i = 1; i <= cc; i++) {
    int x;
    cin >> x;
    c.push_back(x);
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x1, y1, x2, y2, id, ans = INF, temp;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
      ans = abs(y1 - y2);
    else {
      if (c.size()) {
        id = lower_bound(c.begin(), c.end(), y1) - c.begin();
        if (id == c.size()) id--;
        ans = abs(c[id] - y1);
        ans += abs(x2 - x1) / v;
        if (abs(x2 - x1) % v) ans++;
        ans += abs(y2 - c[id]);
        if (id != 0) {
          temp = abs(y1 - c[id - 1]);
          temp += abs(x2 - x1) / v;
          if (abs(x2 - x1) % v) temp++;
          temp += abs(y2 - c[id - 1]);
          ans = min(ans, temp);
        }
      }
      if (l.size()) {
        id = lower_bound(l.begin(), l.end(), y1) - l.begin();
        if (id == l.size()) id--;
        temp = abs(l[id] - y1);
        temp += abs(x2 - x1);
        temp += abs(y2 - l[id]);
        ans = min(ans, temp);
        if (id != 0) {
          temp = abs(y1 - l[id - 1]);
          temp += abs(x2 - x1);
          temp += abs(y2 - l[id - 1]);
          ans = min(ans, temp);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
