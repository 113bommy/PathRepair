#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
struct lem {
  int m, v, i;
} x[100010];
bool comp(lem a, lem b) { return a.m > b.m || a.m == b.m && a.v > b.v; }
int main() {
  int n, k;
  double h;
  scanf("%d%d%lf", &n, &k, &h);
  for (int i = 0; i < n; i++) x[i].i = i;
  for (int i = 0; i < n; i++) scanf("%d", &x[i].m);
  for (int i = 0; i < n; i++) scanf("%d", &x[i].v);
  sort(x, x + n, comp);
  double lb = 0, rb = 1000000100;
  for (int g = 0; g < 150; g++) {
    double mid = (lb + rb) / 2;
    if (g == 149) mid = rb;
    int cnt = k;
    ans.clear();
    for (int i = 0; i < n; i++) {
      if (mid * x[i].v - h * cnt + 10e-10 >= 0) {
        cnt--;
        ans.push_back(x[i].i + 1);
      }
      if (cnt == 0) break;
    }
    if (cnt > 0)
      lb = mid;
    else
      rb = mid;
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    printf("%d%c", ans[i], i == 0 ? '\n' : ' ');
}
