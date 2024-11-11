#include <bits/stdc++.h>
using namespace std;
int n;
long long x[1005], y[1005], r[1005];
struct node {
  long long x, y, r;
  int h;
} p[1005];
bool cmp(const node &a, const node &b) { return a.r > b.r; }
vector<int> v[1005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld%lld%lld", &p[i].x, &p[i].y, &p[i].r);
  double ans = 0;
  int cur = 0;
  sort(p, p + n, cmp);
  int a;
  bool flag;
  for (int i = 0; i < n; i++) {
    flag = false;
    for (int j = cur; j >= 1 && !flag; j--) {
      for (int k = 0; k < v[j].size(); k++) {
        a = v[j][k];
        if ((p[a].x - p[i].x) * (p[a].x - p[i].x) +
                (p[a].y - p[i].y) * (p[a].y - p[i].y) <=
            (p[a].r - p[i].r) * (p[a].r - p[i].r)) {
          p[i].h = p[a].h + 1;
          flag = true;
          break;
        }
      }
    }
    if (!flag) p[i].h = 1;
    v[p[i].h].push_back(i);
    cur = max(cur, p[i].h);
  }
  for (int i = 0; i < n; i++) {
    if (p[i].h == 1 || p[i].h % 2 == 0)
      ans += 3.1415926535 * p[i].r * p[i].r;
    else
      ans -= 3.1415926535 * p[i].r * p[i].r;
  }
  printf("%f", ans);
  return 0;
}
