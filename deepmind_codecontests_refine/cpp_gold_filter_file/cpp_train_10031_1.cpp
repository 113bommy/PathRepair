#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> q[100005];
int T[270000], M;
void update(int p, int v) {
  int l = p + M;
  while (l) {
    T[l] += v;
    l >>= 1;
  }
}
int qq(int l, int r) {
  int aa = 0;
  for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) aa += T[l ^ 1];
    if (r & 1) aa += T[r ^ 1];
  }
  return aa;
}
int a[100005], ans[100005];
vector<int> p[100005];
int main() {
  scanf("%d%d", &n, &m);
  for (M = 1; n + 2 > M; M <<= 1)
    ;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int l, r;
  for (int(i) = 0; (i) < (int)(m); (i)++) {
    scanf("%d%d", &l, &r);
    q[r].push_back({l, i});
  }
  for (int i = 1; i <= n; i++) {
    int t = a[i];
    if (t <= 100000) {
      p[t].push_back(i);
      int ss = p[t].size();
      if (ss >= t) {
        update(p[t][ss - t], 1);
      }
      if (ss > t) {
        update(p[t][ss - t - 1], -2);
      }
      if (ss > t + 1) {
        update(p[t][ss - t - 2], 1);
      }
    }
    for (auto x : q[i]) {
      int l = x.first, id = x.second;
      ans[id] = qq(l, i);
    }
  }
  for (int(i) = 0; (i) < (int)(m); (i)++) printf("%d\n", ans[i]);
  return 0;
}
