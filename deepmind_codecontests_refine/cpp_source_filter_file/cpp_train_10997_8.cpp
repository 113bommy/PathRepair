#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 320;
const double eps = 1e-8;
int n, block;
struct node {
  int pos, high, inc;
} a[N];
struct ask {
  int l, r, t, id;
} q[N];
vector<node> b[M];
int up[M], ans[N];
bool cmpa(ask a, ask b) { return a.t < b.t; }
bool cmpn(node a, node b) {
  if (a.inc == b.inc) return a.high < b.high;
  return a.inc < b.inc;
}
bool canDel(long long k1, long long b1, long long k2, long long b2,
            long long k3, long long b3) {
  return k1 * b2 - k2 * b1 <= k3 * (b2 - b1) + b3 * (k1 - k2);
}
void init() {
  memset(up, 0, sizeof(up));
  block = sqrt(n) + 1 - eps;
  for (int i = 0; i < block; i++) b[i].clear();
}
void preT() {
  vector<node> tmp;
  for (int i = 0; i < block; i++) {
    tmp.resize(b[i].size());
    for (int j = 0; j < b[i].size(); j++) tmp[j] = b[i][j];
    b[i].clear();
    sort(tmp.begin(), tmp.end(), cmpn);
    for (int j = 0; j < tmp.size(); j++) {
      while (b[i].size() > 1) {
        int k = b[i].size() - 1;
        if (canDel(b[i][k - 1].inc, b[i][k - 1].high, b[i][k].inc, b[i][k].high,
                   tmp[j].inc, tmp[j].high))
          b[i].pop_back();
        else
          break;
      }
      b[i].push_back(tmp[j]);
    }
  }
}
int Query(int x, int y, long long t) {
  int l = x / block, r = y / block, pos;
  long long tmp, mx = -1;
  if (l == r) {
    for (int i = x; i <= y; i++) {
      tmp = a[i].inc * t + a[i].high;
      if (mx < tmp) {
        mx = tmp;
        pos = i;
      }
    }
  } else {
    if (x % block)
      for (int sl = min(l * block + block, n); x < sl; x++) {
        tmp = a[x].inc * t + a[x].high;
        if (mx < tmp) {
          mx = tmp;
          pos = x;
        }
      }
    if (y % block != block - 1)
      for (int fl = max(1, r * block); y >= fl; y--) {
        tmp = a[y].inc * t + a[y].high;
        if (mx < tmp) {
          mx = tmp;
          pos = y;
        }
      }
    for (l = x / block, r = y / block; l <= r; l++) {
      while (up[l] < b[l].size() - 1) {
        if (b[l][up[l]].inc * t + b[l][up[l]].high <=
            b[l][up[l] + 1].inc * t + b[l][up[l] + 1].high)
          up[l]++;
        else
          break;
      }
      tmp = b[l][up[l]].inc * t + b[l][up[l]].high;
      if (mx < tmp) {
        mx = tmp;
        pos = b[l][up[l]].pos;
      }
    }
  }
  return pos;
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  init();
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].high, &a[i].inc);
    a[i].pos = i;
    b[i / block].push_back(a[i]);
  }
  preT();
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].t);
    q[i].id = i;
  }
  sort(q, q + m, cmpa);
  for (int i = 0; i < m; i++)
    ans[q[i].id] = Query(q[i].l - 1, q[i].r - 1, q[i].t);
  for (int i = 0; i < m; i++) printf("%d\n", ans[i] + 1);
  return 0;
}
