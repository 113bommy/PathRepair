#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, int> p[100100];
int m[100100][17], ans[100100], n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &p[i].first.first, &p[i].first.second);
    p[i].second = i;
  }
  sort(p, p + n);
  for (int i = n - 1; i >= 0; --i) {
    int le = i, ri = n - 1, mid, t = n;
    while (le <= ri) {
      mid = (le + ri) >> 1;
      if (p[mid].first.first > p[i].first.first + p[i].first.second - 1)
        ri = mid - 1, t = mid;
      else
        le = mid + 1;
    }
    int r = t;
    for (int j = 0, s = i + 1; s != t; ++j)
      if ((t - s) & (1 << j)) {
        r = max(r, m[s][j]);
        s += 1 << j;
      }
    ans[p[i].second] = r - i;
    m[i][0] = r;
    for (int j = 0; j < 16; ++j)
      m[i][j + 1] = max(m[i][j], m[min(n, i + (1 << j))][j]);
  }
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}
