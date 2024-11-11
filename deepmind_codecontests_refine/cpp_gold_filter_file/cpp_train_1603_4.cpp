#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
long long ln, lk, lm;
struct qy {
  int l, r, id;
  bool operator<(const qy &o) const {
    if (l == o.l) return r > o.r;
    return l < o.l;
  }
} q[200105];
bool ud[200105];
bool dd(int &i, int &ed) {
  int j;
  int ml = ed, tar = -1;
  for (j = i; j < m; j++) {
    if (q[j].l > ed) break;
    if (q[j].r > ml) {
      tar = j;
      ml = q[j].r;
    }
  }
  if (tar != -1) {
    ud[tar] = 1;
    ed = q[tar].r;
  }
  i = j;
  return tar != -1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = 0; (i) < (int)(m); (i)++) {
    scanf("%d%d", &q[i].l, &k);
    q[i].r = q[i].l + k;
    q[i].id = i + 1;
  }
  sort(q, q + m);
  ud[0] = 1;
  int ed = q[0].r;
  for (int i = 0; i < m;) {
    if (dd(i, ed)) continue;
    if (i < m) {
      ud[i] = 1;
      ed = q[i].r;
    }
  }
  vector<int> ans;
  for (int(i) = 0; (i) < (int)(m); (i)++)
    if (!ud[i]) ans.push_back(q[i].id);
  printf("%d\n", ans.size());
  for (int c : ans) printf("%d ", c);
  return 0;
}
