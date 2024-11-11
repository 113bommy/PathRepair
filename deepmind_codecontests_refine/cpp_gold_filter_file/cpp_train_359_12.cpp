#include <bits/stdc++.h>
using namespace std;
using namespace std;
const double eps = 1e-12;
int sgn(double k) { return (k > -eps) - (k < eps); }
typedef struct {
  double x, y;
  int id;
} dot;
dot operator-(dot a, dot b) { return (dot){a.x - b.x, a.y - b.y}; }
dot operator+(dot a, dot b) { return (dot){a.x + b.x, a.y + b.y}; }
dot operator*(double k, dot a) { return (dot){a.x * k, a.y * k}; }
double operator*(dot a, dot b) { return a.x * b.y - a.y * b.x; }
double atan2(dot a) { return atan2(a.y, a.x); }
int cmp(dot a, dot b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
int cmp2(dot a, dot b) { return a.id < b.id; }
dot d[200514], tb[200514];
int ct, dt;
int n, bad[200514];
map<pair<int, int>, int> mp;
vector<int> e[200514];
int ans[200514], at;
void sol() {
  mp.clear();
  dt = 0;
  for (int i = 0; i < n; i++) {
    e[i + 1].clear();
    int x, y;
    scanf("%d %d", &(x), &(y));
    pair<int, int> pp = pair<int, int>(x, y);
    int t = mp[pp];
    if (t) {
      e[t].push_back(i + 1);
      continue;
    }
    d[dt++] = (dot){100000.0 / x, 100000.0 / y, i + 1};
    mp[pp] = i + 1;
    e[i + 1].push_back(i + 1);
  }
  sort(d, d + dt, cmp);
  int st = 0;
  ct = 0;
  for (int i = dt - 1; i >= 0; i--) {
    for (; ct >= 2 && sgn((tb[ct - 1] - tb[ct - 2]) * (d[i] - tb[ct - 1])) > 0;
         ct--)
      ;
    tb[ct++] = d[i];
  }
  for (; ct - st >= 2 && sgn(atan2(tb[st] - tb[st + 1])) >= 0; st++)
    ;
  for (; ct - st >= 2 &&
         sgn(atan2(tb[ct - 1] - tb[ct - 2]) - acos(-1) / 2.0) <= 0;
       ct++)
    ;
  at = 0;
  for (int i = st; i < ct; i++) {
    for (auto it : e[tb[i].id]) {
      ans[at++] = it;
    }
  }
  sort(ans, ans + at);
  for (int i = 0; i < at; i++) printf("%d ", ans[i]);
  puts("");
}
int main() {
  scanf("%d", &(n));
  sol();
  return 0;
}
