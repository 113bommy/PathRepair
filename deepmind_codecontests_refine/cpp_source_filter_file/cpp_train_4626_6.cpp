#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Event {
  int x, type;
  bool operator<(const Event& a) const {
    return x < a.x || (x == a.x && type < a.type);
  }
};
Event e[205];
int main() {
  int n, l, r, c = 0, L, R;
  int v[105];
  cin >> n;
  cin >> L >> R;
  for (int i = 1; i < n; ++i) {
    cin >> l >> r;
    e[c++] = (Event){l, 0};
    e[c++] = (Event){r, 1};
  }
  sort(e, e + c);
  memset(v, 0, sizeof v);
  int cnt = 0, pre = -1;
  for (int i = 0; i < c; ++i) {
    if (pre != -1) {
      for (int j = pre; j <= e[i].x; ++j) v[j] = cnt;
    }
    if (e[i].type == 0)
      cnt++;
    else
      cnt--;
    pre = e[i].x;
  }
  int ans = 0;
  for (int i = L; i < R; ++i)
    if (!v[i]) ans++;
  cout << ans << endl;
  return 0;
}
