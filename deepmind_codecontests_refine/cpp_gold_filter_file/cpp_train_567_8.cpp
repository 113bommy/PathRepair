#include <bits/stdc++.h>
using namespace std;
long long h[200001], d[200001];
struct Node {
  long long Min, Max, sum;
} Tree[2000001];
int N, n, i, m, a, b;
long long ans, Min;
void build_tree(int l, int r, int t) {
  if (l == r)
    Tree[t].Max = d[l] + 2 * h[l], Tree[t].Min = d[l] - 2 * h[r];
  else {
    build_tree(l, ((l + r) >> 1), (t << 1));
    build_tree(((l + r) >> 1) + 1, r, ((t << 1) + 1));
    Tree[t].sum = max(Tree[(t << 1)].sum,
                      max(Tree[((t << 1) + 1)].sum,
                          Tree[((t << 1) + 1)].Max - Tree[(t << 1)].Min));
    Tree[t].Min = min(Tree[(t << 1)].Min, Tree[((t << 1) + 1)].Min);
    Tree[t].Max = max(Tree[(t << 1)].Max, Tree[((t << 1) + 1)].Max);
  }
}
void ask(int ll, int rr, int l, int r, int t) {
  if (ll <= l && r <= rr) {
    ans = max(ans, max(Tree[t].sum, Tree[t].Max - Min));
    Min = min(Min, Tree[t].Min);
  } else {
    if (ll <= ((l + r) >> 1)) ask(ll, rr, l, ((l + r) >> 1), (t << 1));
    if (rr > ((l + r) >> 1)) ask(ll, rr, ((l + r) >> 1) + 1, r, ((t << 1) + 1));
  }
}
int main() {
  scanf("%d%d", &n, &m);
  N = 2 * n;
  for (i = 2; i <= n + 1; i++) scanf("%I64d", &d[i]);
  for (i = n + 2; i <= N; i++) d[i] = d[i - n];
  for (i = 1; i <= n; i++) scanf("%I64d", &h[i]), h[i + n] = h[i];
  for (i = 2; i <= N; i++) d[i] += d[i - 1];
  build_tree(1, N, 1);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    ans = 0;
    Min = (long long)1e18;
    if (a <= b)
      ask(b + 1, a + n - 1, 1, N, 1);
    else
      ask(b + 1, a - 1, 1, N, 1);
    printf("%I64d\n", ans);
  }
}
