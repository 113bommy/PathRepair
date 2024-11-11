#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e3 + 5;
struct Edge {
  int u, v, w;
  bool operator<(const Edge& t) const { return w < t.w; }
} E[maxN];
int f[maxN];
int N;
int _sum;
int sum[maxN];
int sz[maxN];
int x[maxN];
int get_f(int x) { return f[x] == x ? x : f[x] = get_f(f[x]); }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N - 1; i++) {
    scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
  }
  for (int i = 1; i <= N; i++) {
    scanf("%d", &x[i]);
    sum[i] = x[i];
    sz[i] = 1;
    f[i] = i;
    _sum += x[i];
  }
  sort(E + 1, E + N);
  int ans = 0;
  for (int i = 1; i < N; i++) {
    int u = E[i].u;
    int v = E[i].v;
    int fu = get_f(u);
    int fv = get_f(v);
    if (sz[fu] + sz[fv] > _sum - sum[fu] - sum[fv]) {
      ans = i;
      break;
    }
    f[fu] = fv;
    sz[fv] += sz[fu];
    sum[fv] += sum[fu];
  }
  printf("%d\n", ans);
  return 0;
}
