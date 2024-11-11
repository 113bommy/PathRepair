#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100010];
int cntx, apx[100010], X[100010], Y[100010], p[100010], q[100010];
void insert(int x, int y) {
  int v = lower_bound(apx, apx + cntx, x) - apx + 1;
  while (v <= cntx) {
    vec[v].push_back(y);
    v += v & -v;
  }
}
int query(int x, int y) {
  int v = lower_bound(apx, apx + cntx, x) - apx + 1, ret = 0;
  while (v > 0) {
    ret += upper_bound(vec[v].begin(), vec[v].end(), y) - vec[v].begin();
    v -= v & -v;
  }
  return ret;
}
void Init() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &X[i], &Y[i]);
    apx[i] = X[i];
    p[i] = X[i], q[i] = Y[i];
  }
  sort(apx, apx + n);
  sort(p, p + n);
  sort(q, q + n);
  cntx = unique(apx, apx + n) - apx;
  for (int i = 0; i < n; i++) insert(X[i], Y[i]);
  for (int i = 1; i <= cntx; i++) sort(vec[i].begin(), vec[i].end());
}
void Solv() {
  int per[10];
  for (int i = 0; i < 9; i++) scanf("%d", &per[i]);
  sort(per, per + 9);
  do {
    int a = per[0] + per[1] + per[2] - 1;
    int b = a + per[3] + per[4] + per[5];
    int c = per[0] + per[3] + per[6] - 1;
    int d = c + per[1] + per[4] + per[7];
    if (p[a] == p[a + 1]) continue;
    if (p[b] == p[b + 1]) continue;
    if (q[c] == q[c + 1]) continue;
    if (q[d] == q[d + 1]) continue;
    if (query(p[a], q[c]) != per[0]) continue;
    if (query(p[a], q[d]) != per[0] + per[1]) continue;
    if (query(p[b], q[c]) != per[0] + per[3]) continue;
    if (query(p[b], q[d]) != per[0] + per[1] + per[3] + per[4]) continue;
    printf("%lf %lf\n%lf %lf\n", p[a] + .5, p[b] + .5, q[c] + .5, q[d] + .5);
    return;
  } while (next_permutation(per, per + 9));
  puts("-1");
}
int main() {
  Init();
  Solv();
}
