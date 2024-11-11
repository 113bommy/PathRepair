#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, int> data[100005];
int n, N, id[100005], vot[100005], f[100005], m;
vector<pair<int, int> > A[100005];
vector<int> B[100005];
int calc(int x) {
  if (vot[0] + x == 0) return 2100000000;
  int sum = 0, cost = 0;
  for (int i = (int)1; i <= (int)m; i++) f[i] = 0;
  for (int i = (int)1; i <= (int)n; i++) {
    int k = vot[0] + x;
    if (k > vot[i]) continue;
    sum += vot[i] - k + 1;
    if (sum > x) return 2100000000;
    cost += B[i][vot[i] - k];
    for (int j = (int)0; j <= (int)vot[i] - k; j++) f[A[i][j].second] = 1;
  }
  int u = x - sum, i = 0;
  while (u) {
    i++;
    if (i > n) return 2100000000;
    if (data[i].first.second == 0) continue;
    if (f[data[i].second]) continue;
    cost += data[i].first.first;
    u--;
  }
  return cost;
}
int main() {
  scanf("%d", &n);
  m = n;
  for (int i = (int)1; i <= (int)n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    A[x].push_back(make_pair(y, i));
    N = max(N, x);
    data[i] = make_pair(make_pair(y, x), i);
  }
  n = N;
  sort(data + 1, data + m + 1);
  for (int i = (int)0; i <= (int)n; i++) sort(A[i].begin(), A[i].end());
  for (int i = (int)0; i <= (int)n; i++) {
    if (A[i].size() == 0) continue;
    B[i].resize(A[i].size());
    B[i][0] = A[i][0].first;
    for (int j = (int)1; j <= (int)A[i].size() - 1; j++) {
      B[i][j] = B[i][j - 1] + A[i][j].first;
    }
  }
  for (int i = (int)0; i <= (int)n; i++) vot[i] = A[i].size();
  int l = 0, r = m;
  int ans = 2100000000;
  while (r - l > 5) {
    int md1 = (2 * l + r) / 3, md2 = (l + 2 * r) / 3;
    int co1 = calc(md1), co2 = calc(md2);
    ans = min(ans, min(co1, co2));
    if (co1 <= co2)
      r = md2;
    else
      l = md1;
  }
  for (int i = (int)l; i <= (int)r; i++) {
    ans = min(ans, calc(i));
  }
  printf("%d\n", ans);
  return 0;
}
