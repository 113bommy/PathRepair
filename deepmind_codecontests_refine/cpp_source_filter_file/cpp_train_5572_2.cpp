#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
pair<int, int> p[2][maxn];
int minp[maxn], mins[maxn], maxp[maxn], maxs[maxn];
int n;
inline long long s(long long x) { return ((x) * (x)); }
long long gao(int x) {
  for (int i = (1); i <= (n); i++) {
    minp[i] = min(minp[i - 1], p[x][i].second);
    maxp[i] = max(maxp[i - 1], p[x][i].second);
  }
  for (int i = (n); i >= (1); i--) {
    mins[i] = min(mins[i + 1], p[x][i].second);
    maxs[i] = max(maxs[i + 1], p[x][i].second);
  }
  long long l = -1, r = 1e18, mid;
  while (r - l > 1) {
    mid = l + r >> 1;
    bool g = s(p[x][n].first - p[x][1].first) <= mid;
    int le = 1, ri = 1;
    while (!g && ri <= n) {
      while (s(p[x][ri].first - p[x][le].first) > mid) le++;
      long long top = max(maxp[le - 1], maxs[ri + 1]),
                bot = min(minp[le - 1], minp[ri + 1]);
      if (s(top - bot) <= mid &&
          max(s(p[x][le].first), s(p[x][ri].first)) + max(s(top), s(bot)) <=
              mid)
        g = 1;
      ri++;
    }
    if (g)
      r = mid;
    else
      l = mid;
  }
  return r;
}
int main() {
  int x, y;
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    scanf("%d%d", &x, &y);
    p[0][i] = pair<int, int>(x, y);
    p[1][i] = pair<int, int>(y, x);
  }
  for (int i = (0); i <= (1); i++) sort(p[i] + 1, p[i] + 1 + n);
  cout << min(gao(0), gao(1)) << endl;
  return 0;
}
