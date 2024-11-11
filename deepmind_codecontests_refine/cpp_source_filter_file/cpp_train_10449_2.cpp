#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100010];
int n, m, X[100010], Y[100010], apx[100010], p[100010], q[100010], num[10];
void add(int x, int y) {
  int v = lower_bound(apx, apx + m, x) - apx + 1;
  for (int i = v; i <= m; i += (i & -i)) vec[i].push_back(y);
}
int query(int x, int y) {
  int v = lower_bound(apx, apx + m, x) - apx + 1, res = 0;
  for (int i = v; i > 0; i -= (i & -i))
    res += upper_bound(vec[i].begin(), vec[i].end(), y) - vec[i].begin();
  return res;
}
void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", X + i, Y + i);
    apx[i] = X[i];
    p[i] = X[i];
    q[i] = Y[i];
  }
  sort(apx, apx + n);
  m = unique(apx, apx + n) - apx;
  for (int i = 0; i < n; i++) add(X[i], Y[i]);
  sort(p, p + n);
  sort(q, q + n);
  for (int i = 1; i <= m; i++) sort(vec[i].begin(), vec[i].end());
}
void sol() {
  for (int i = 0; i < 10; i++) scanf("%d", num + i);
  sort(num, num + 10);
  do {
    int a = num[0] + num[1] + num[2] - 1;
    int b = a + num[3] + num[4] + num[5];
    int c = num[0] + num[3] + num[6] - 1;
    int d = c + num[1] + num[4] + num[7];
    if (p[a] == p[a + 1]) continue;
    if (p[b] == p[b + 1]) continue;
    if (q[c] == q[c + 1]) continue;
    if (q[d] == q[d + 1]) continue;
    if (query(p[a], q[c]) != num[0]) continue;
    if (query(p[a], q[d]) != num[0] + num[1]) continue;
    if (query(p[b], q[c]) != num[0] + num[3]) continue;
    if (query(p[b], q[d]) != num[0] + num[1] + num[3] + num[4]) continue;
    printf("%.8f %.8f\n%.8f %.8f\n", p[a] + 0.5, p[b] + 0.5, q[c] + 0.5,
           q[d] + 0.5);
    return;
  } while (next_permutation(num, num + 10));
  puts("-1");
}
int main() {
  init();
  sol();
  return 0;
}
