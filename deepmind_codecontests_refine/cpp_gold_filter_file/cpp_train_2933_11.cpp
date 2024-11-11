#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 9;
vector<tuple<int, int>> v(N, {1e9 + 7, 0});
tuple<int, int, int, int> ans{1, 0, 0, 0};
int n, m, a[N], b[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int t, j, s; n--; ++a[s])
    for (scanf("%d", &t), s = 0; t--; s |= 1 << j - 1) scanf("%d", &j);
  for (int i = 0; i < N; ++i)
    for (int j = i; j; j = i & j - 1) b[i] += a[j];
  for (int i = 1, c, t, j, s; i <= m; ++i) {
    for (scanf("%d%d", &c, &t), s = 0; t--; s |= 1 << j - 1) scanf("%d", &j);
    for (int k = 0; k < N; ++k)
      if (get<1>(v[k]))
        ans = min(ans, {-b[s | k], c + get<0>(v[k]), get<1>(v[k]), i});
    v[s] = min(v[s], {c, i});
  }
  printf("%d %d", get<2>(ans), get<3>(ans));
}
