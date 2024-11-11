#include <bits/stdc++.h>
using namespace std;
int n, m, nrE;
struct Dish {
  int p, s, b;
} d[100002];
struct Person {
  int inc, pref;
} v[100002];
struct Event {
  int x, y, z, t;
  bool operator<(const Event &ot) const {
    if (x == ot.x) return z > ot.z;
    return x < ot.x;
  }
} E[100002 * 3];
unordered_map<int, int> Bit[2];
int ans[100002];
void Add(int t, int i, int val) {
  for (; i < 2 * 1000000005 && i > 0; i += (i & (-i))) Bit[t][i] += val;
}
int Sum(int t, int i) {
  int ret = 0;
  for (; i > 0; i -= (i & (-i))) ret += Bit[t][i];
  return ret;
}
void readDish() {
  for (int i = 0; i < n; ++i) scanf("%d", &d[i].p);
  for (int i = 0; i < n; ++i) scanf("%d", &d[i].s);
  for (int i = 0; i < n; ++i) scanf("%d", &d[i].b);
}
void readPers() {
  for (int i = 0; i < m; ++i) scanf("%d", &v[i].inc);
  for (int i = 0; i < m; ++i) scanf("%d", &v[i].pref);
}
void solveEvents() {
  sort(E, E + nrE);
  for (int i = 0; i < nrE; ++i) {
    if (E[i].z <= 0) {
      int idx = -E[i].z;
      ans[idx] = Sum(0, v[idx].inc + v[idx].pref) +
                 Sum(1, v[idx].pref - v[idx].inc + 1000000005);
    } else {
      Add(0, E[i].x + E[i].y, 1 * E[i].t);
      Add(1, E[i].z - E[i].x + 1000000005, -1 * E[i].t);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  readDish();
  readPers();
  for (int i = 0; i < n + m; ++i) {
    if (i < n) {
      E[nrE++] = {d[i].p, d[i].b, d[i].b + 1, 1};
      E[nrE++] = {d[i].s + 1, d[i].b - (d[i].s - d[i].p + 1),
                  d[i].b + (d[i].s - d[i].p + 1) + 1, -1};
    } else
      E[nrE++] = {v[i - n].inc, v[i - n].pref, n - i, 0};
  }
  solveEvents();
  for (int i = 0; i < m; ++i) printf("%d ", ans[i]);
  return 0;
}
