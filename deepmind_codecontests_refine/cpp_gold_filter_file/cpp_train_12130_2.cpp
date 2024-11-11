#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1, M = 1e6 + 1;
pair<int, int> v[N];
int d[N], a[M];
int main() {
  int n, x, y, ans, j = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &x, &y), v[i] = make_pair(x, y);
  sort(v, v + n);
  for (int i = 0; i < M; ++i) {
    while (j < n && v[j].first < i) j++;
    a[i] = j;
  }
  d[0] = 0;
  for (int i = 1; i < n; ++i) {
    int r = v[i].first - v[i].second;
    if (r < 0)
      d[i] = i;
    else {
      d[i] = i - a[r];
      if (a[r] > 0) d[i] += d[a[r] - 1];
    }
  }
  ans = d[n - 1];
  for (int i = 0; i < n; ++i) ans = min(ans, d[i - 1] + n - i);
  printf("%d\n", ans);
  return 0;
}
