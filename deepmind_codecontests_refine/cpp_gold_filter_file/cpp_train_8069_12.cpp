#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
struct Point {
  int x, y;
  bool operator<(const Point &t) const { return y > t.y; }
};
int r, c, n, k;
Point point[N];
long long ans;
int pl[N], pr[N], cnt[N];
void del(int x, long long &sum) {
  int tmp = cnt[x], d = point[pl[x]].y - point[x].y;
  sum -= cnt[x] * point[x].y;
  pr[pl[x]] = pr[x], pl[pr[x]] = pl[x];
  for (int t = 1; t < k; ++t) {
    if ((x = pr[x]) > n) return;
    sum -= cnt[x] * point[x].y;
    swap(tmp, cnt[x]);
    sum += cnt[x] * point[x].y;
  }
  if ((x = pr[x]) > n) return;
  sum += d * point[x].y;
  cnt[x] += d;
}
vector<int> lines[N];
int main() {
  scanf("%d %d %d %d", &r, &c, &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d %d", &point[i].x, &point[i].y);
  sort(point + 1, point + 1 + n), point[0].y = c + 1;
  for (int i = 1; i <= n; ++i) lines[point[i].x].push_back(i);
  for (int i = 1; i <= r; ++i) {
    memset(pl, 0, (n + 2) * sizeof(int));
    memset(pr, 0, (n + 2) * sizeof(int));
    memset(cnt, 0, (n + 2) * sizeof(int));
    int p = 0;
    for (int j = 1; j <= n; ++j)
      if (point[j].x >= i) {
        pr[p] = j;
        pl[j] = p;
        p = j;
      }
    pr[p] = n + 1;
    long long sum = 0;
    for (int x = pr[0], pos = 1, las = 0; x <= n; x = pr[x], pos++)
      if (pos == k) {
        cnt[x] = point[las].y - point[pr[las]].y;
        pos--, las = pr[las];
        sum += cnt[x] * point[x].y;
      }
    ans += sum;
    for (int j = r; j > i; --j) {
      for (int x : lines[j]) del(x, sum);
      ans += sum;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
