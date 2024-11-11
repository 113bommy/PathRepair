#include <bits/stdc++.h>
using namespace std;
int l[10], r[10];
double ans;
int n;
void dfs(int i, int cnt, int eq, int v, double p) {
  if (i == n) {
    if (cnt <= 1 && cnt + eq >= 2) ans += p * v;
    return;
  }
  if (l[i] < v)
    dfs(i + 1, cnt, eq, v,
        p * min(1.0, (double)(v - l[i]) / (r[i] - l[i] + 1)));
  if (l[i] <= v && v <= r[i]) dfs(i + 1, cnt, eq + 1, v, p / (r[i] - l[i] + 1));
  if (r[i] > v)
    dfs(i + 1, cnt + 1, eq, v,
        p * min(1.0, (double)(r[i] - v) / (r[i] - l[i] + 1)));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", l + i, r + i);
  for (int i = 1; i <= 10000; ++i) dfs(0, 0, 0, i, 1);
  printf("%.10f\n", ans);
}
