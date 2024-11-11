#include <bits/stdc++.h>
using namespace std;
constexpr int kN = int(2E5 + 10);
int a[kN], b[kN], sz[kN], val[kN], p[kN];
vector<int> A[kN];
int Find(int n) { return n == p[n] ? n : p[n] = Find(p[n]); }
int main() {
  int m, n, l, r;
  long long int ans = 0, mx;
  vector<tuple<int, int, int>> edges;
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n + m; i++) p[i] = i;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &sz[i]);
    A[i].resize(sz[i] + 1);
    for (int j = 1; j <= sz[i]; j++) scanf("%d", &A[i][j]);
  }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= sz[i]; j++)
      edges.push_back({a[i] + b[A[i][j]], i, A[i][j] + m});
  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());
  for (tuple<int, int, int> i : edges) {
    l = Find(get<1>(i)), r = Find(get<2>(i));
    if (l == r)
      ans += get<0>(i);
    else
      p[l] = r;
  }
  printf("%lld\n", ans);
}
