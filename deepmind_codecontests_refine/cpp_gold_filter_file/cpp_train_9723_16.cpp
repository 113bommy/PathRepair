#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, m, f[N], L[N], R[N], id2q[N];
struct Query {
  int t, x, y;
} q[N];
inline int get(int x) { return x == f[x] ? x : f[x] = get(f[x]); }
struct SegTree {
  vector<int> id[N << 2];
  void merge(int t, int l, int r, int P, int ID) {
    for (int i = (0); i < (((int)(id[t]).size())); ++i) {
      L[ID] = min(L[ID], L[id[t][i]]);
      R[ID] = max(R[ID], R[id[t][i]]);
      f[get(id[t][i])] = ID;
    }
    id[t].clear();
    if (l < r) {
      int z = (l + r) >> 1;
      if (P <= z)
        merge(((t) << 1), l, z, P, ID);
      else
        merge(((t) << 1 | 1), z + 1, r, P, ID);
    }
  }
  void insert(int t, int l, int r, int L, int R, int ID) {
    if (L <= l && r <= R) {
      id[t].push_back(ID);
      return;
    }
    int z = (l + r) >> 1;
    if (L <= z) insert(((t) << 1), l, z, L, R, ID);
    if (R > z) insert(((t) << 1 | 1), z + 1, r, L, R, ID);
  }
} seg;
int main() {
  scanf("%d", &n);
  vector<int> V;
  for (int i = (0); i < (n); ++i) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    q[i] = (Query){t, x, y};
    if (t == 1) {
      f[m] = m;
      ++m, V.push_back(x), V.push_back(y);
    }
  }
  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());
  for (int i = (0); i < (n); ++i)
    if (q[i].t == 1) {
      q[i].x = lower_bound(V.begin(), V.end(), q[i].x) - V.begin() + 1;
      q[i].y = lower_bound(V.begin(), V.end(), q[i].y) - V.begin() + 1;
    }
  m = 0;
  for (int i = (0); i < (n); ++i) {
    if (q[i].t == 1) {
      int _l = q[i].x, _r = q[i].y;
      L[m] = _l, R[m] = _r, id2q[m] = i;
      seg.merge(1, 1, ((int)(V).size()), _l, m);
      seg.merge(1, 1, ((int)(V).size()), _r, m);
      if (L[m] + 1 <= R[m] - 1)
        seg.insert(1, 1, ((int)(V).size()), L[m] + 1, R[m] - 1, m);
      ++m;
    } else {
      if (get(q[i].x - 1) == get(q[i].y - 1)) {
        puts("YES");
      } else {
        int la = q[id2q[q[i].x - 1]].x;
        int ra = q[id2q[q[i].x - 1]].y;
        int fb = get(q[i].y - 1);
        puts((L[fb] < la && la < R[fb]) || (L[fb] < ra && ra < R[fb]) ? "YES"
                                                                      : "NO");
      }
    }
  }
  return 0;
}
