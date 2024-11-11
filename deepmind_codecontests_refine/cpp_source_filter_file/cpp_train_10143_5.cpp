#include <bits/stdc++.h>
using namespace std;
vector<int> ans[2002];
int n, c[2002], r[2002], dp[2002], tag[2002], val[2002], d[2002], d2[2002],
    bound[2002], d3[2002], tag_ans[2001];
bool cmp(int i, int j) { return r[i] < r[j]; }
bool cmp2(int i, int j) { return c[i] < c[j]; }
void DFS(int x) {
  tag_ans[x] = 1;
  for (int i = 0; i < ans[x].size(); i++) DFS(ans[x][i]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &c[i], &r[i]), d[i] = d2[i] = i, c[i] -= r[i];
  c[n] = -1000000005;
  r[n] = 1000000005;
  d[n] = d2[n] = n;
  n++;
  sort(d, d + n, cmp);
  sort(d2, d2 + n, cmp2);
  for (int i = 0; i < n; i++) {
    int run = i;
    while (run < n && c[d2[i]] + 2 * r[d2[i]] > c[d2[run]]) run++;
    bound[d2[i]] = run;
  }
  for (int i = 0; i < n; i++) d3[d2[i]] = i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) dp[j] = 0, tag[j] = -1;
    int high = 0, save = 0;
    for (int j = 0; j <= n; j++) {
      if (high > dp[j]) {
        dp[j] = high;
        tag[j] = tag[j - 1];
      } else
        high = dp[j];
      if (j == n || c[d2[j]] < c[d[i]] ||
          c[d2[j]] + 2 * r[d2[j]] > c[d[i]] + 2 * r[d[i]])
        continue;
      if (dp[bound[d2[j]]] < high + val[d2[j]]) {
        dp[bound[d2[j]]] = high + val[d2[j]];
        tag[bound[d2[j]]] = d2[j];
      }
    }
    val[d[i]] = dp[bound[d[i]]] + 1;
    save = bound[d[i]];
    while (tag[save] != -1 && c[tag[save]] >= c[d[i]]) {
      ans[d[i]].push_back(tag[save]);
      save = d3[tag[save]];
    }
  }
  printf("%d\n", val[n - 1] - 1);
  DFS(n - 1);
  for (int i = 0; i < n - 1; i++)
    if (tag_ans[i]) printf("%d ", i + 1);
  return 0;
}
