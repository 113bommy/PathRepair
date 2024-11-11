#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int inf = 1e9;
struct pt {
  int x, l;
};
inline bool operator<(const pt &a, const pt &b) { return a.x < b.x; }
pt p[maxn];
int n;
vector<int> xs;
int ans[3 * maxn][maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i].x, &p[i].l);
    xs.push_back(p[i].x);
    xs.push_back(p[i].x - p[i].x);
    xs.push_back(p[i].x + p[i].x);
  }
  xs.push_back(-inf);
  sort(begin(xs), end(xs));
  xs.resize(unique(begin(xs), end(xs)) - xs.begin());
  sort(p, p + n);
  for (int i = 0; i < (int)xs.size(); i++) {
    for (int j = 0; j < n; j++)
      if (p[j].x >= xs[i]) {
        for (int t = j; t < n; t++)
          if (p[t].x - p[t].l <= p[j].x) {
            int left_fdg = p[t].x - p[t].l;
            int right_fdg = p[t].x;
            int k = j;
            while (k < n && p[k].x <= right_fdg) {
              if (k != t) right_fdg = max(right_fdg, p[k].x + p[k].l);
              k++;
            }
            int wh = lower_bound(begin(xs), end(xs), right_fdg) - xs.begin();
            ans[wh][k] =
                max(ans[wh][k], ans[i][j] + right_fdg - max(left_fdg, xs[i]));
          }
        int left_fdg = p[j].x;
        int right_fdg = p[j].x;
        int k = j;
        while (k < n && p[k].x <= right_fdg) {
          right_fdg = max(right_fdg, p[k].x + p[k].l);
          k++;
        }
        int wh = lower_bound(begin(xs), end(xs), right_fdg) - xs.begin();
        ans[wh][k] =
            max(ans[wh][k], ans[i][j] + right_fdg - max(left_fdg, xs[i]));
      }
  }
  int answer = 0;
  for (int i = 0; i < (int)xs.size(); i++) answer = max(answer, ans[i][n]);
  cout << answer << endl;
  return 0;
}
