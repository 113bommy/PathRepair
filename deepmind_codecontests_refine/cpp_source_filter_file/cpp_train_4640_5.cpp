#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Pos {
  int c, v;
  Pos(int c, int v) : c(c), v(v){};
};
vector<Pos> v;
int main() {
  int k, s, tm;
  scanf("%d%d%d%d", &n, &k, &s, &tm);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v.push_back(Pos(x, y));
  }
  vector<int> h;
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    h.push_back(x);
  }
  h.push_back(s);
  h.push_back(0);
  sort(h.begin(), h.end());
  int l = 0, r = s + 1;
  while (r - l > 1) {
    int t = (l + r) / 2;
    int tp = 0;
    for (int i = 1; i <= k + 1; i++) {
      int rast = h[i] - h[i - 1];
      if (rast > t) {
        tp += s + 1;
        break;
      }
      tp += max(2 * rast - (t - rast), rast);
    }
    if (tp > tm)
      l = t;
    else
      r = t;
  }
  if (r == s + 1)
    printf("-1");
  else {
    int ans = 1e9 + 2;
    for (int i = 0; i < n; i++) {
      if (v[i].v >= r) ans = min(ans, v[i].c);
    }
    if (ans == 1e9 + 2) ans = -1;
    printf("%d", ans);
  }
}
