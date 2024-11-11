#include <bits/stdc++.h>
using namespace std;
using namespace std;
int ban[55][55];
struct E {
  int k, c;
  E() {}
  E(int _k, int _c) : k(_k), c(_c) {}
} es[4200010];
struct Flow {
  int n, m, dis[55];
  int qq[55], qr, ql;
  vector<int> e[55];
  void init(int _n) {
    n = _n;
    m = 0;
    for (int i = 0; i < n; i++) e[i] = vector<int>();
  }
  void add(int a, int b, int c) {
    e[a].push_back(m);
    es[m] = E(b, c);
    m++;
    e[b].push_back(m);
    es[m] = E(a, 0);
    m++;
  }
  bool BFS() {
    memset(dis, -1, n * sizeof(int));
    ql = qr = 0;
    qq[qr++] = 0;
    dis[0] = 0;
    while (ql != qr && dis[n - 1] == -1) {
      int p = qq[ql++];
      for (__typeof((e[p]).begin()) it = (e[p]).begin(); it != (e[p]).end();
           it++) {
        E ee = es[*it];
        if (ee.c == 0 || dis[ee.k] != -1) continue;
        dis[ee.k] = dis[p] + 1;
        qq[qr++] = ee.k;
      }
    }
    return dis[n - 1] != -1;
  }
  long long go(int p, long long c) {
    if (p == n - 1) return c;
    long long ret = 0, tmp;
    for (__typeof((e[p]).begin()) it = (e[p]).begin(); it != (e[p]).end();
         it++) {
      E &ee = es[*it];
      if (ee.c == 0 || dis[p] + 1 != dis[ee.k]) continue;
      tmp = go(ee.k, min(c - ret, (long long)ee.c));
      ret += tmp;
      ee.c -= tmp;
      es[(*it) ^ 1].c += tmp;
      if (ret == c) break;
    }
    if (ret == 0) dis[p] = -1;
    return ret;
  }
  long long maxflow() {
    long long ret = 0;
    while (BFS()) ret += go(0, 1LL << 60);
    return ret;
  }
} flow;
int ee[55][55], mi[55], in_queue[55], bb[55 * 55 * 55 * 55], last[55],
    add[55][55];
bool fresh(int &x, int v) {
  if (x > v) {
    x = v;
    return true;
  }
  return false;
}
bool go(int &K, int n) {
  if (!K) return false;
  for (int i = 0; i < (n); ++i) mi[i] = 1034567890;
  mi[0] = 0;
  bb[0] = 0;
  in_queue[0] = 1;
  for (int i = 0, j = 1; i < j; i++) {
    int x = bb[i];
    in_queue[x] = 0;
    for (int k = 0; k < n; k++) {
      if (add[x][k] > 0) {
        if (fresh(mi[k], mi[x] - 1)) {
          last[k] = x;
          if (!in_queue[k]) {
            in_queue[k] = 1;
            bb[j++] = k;
          }
        }
      } else {
        if (ee[x][k] > 0) {
          if (fresh(mi[k], mi[x])) {
            last[k] = x;
            if (!in_queue[k]) {
              in_queue[k] = 1;
              bb[j++] = k;
            }
          }
        } else if (!ban[x][k]) {
          if (fresh(mi[k], mi[x] + 1)) {
            last[k] = x;
            if (!in_queue[k]) {
              in_queue[k] = 1;
              bb[j++] = k;
            }
          }
        }
      }
    }
  }
  if (mi[n - 1] > K) return false;
  K -= mi[n - 1];
  int now = n - 1;
  while (now) {
    if (add[last[now]][now] > 0) {
      add[last[now]][now]--;
    } else if (ee[last[now]][now] > 0) {
      ee[last[now]][now]--;
      ee[now][last[now]]++;
    } else {
      add[now][last[now]]++;
    }
    now = last[now];
  }
  return true;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  flow.init(n);
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (n); ++j) {
      int(v);
      scanf("%d", &v);
      if (!v) ban[i][j] = 1;
      if (v) flow.add(i, j, v);
    }
  int an = flow.maxflow();
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (((int)(flow.e[i]).size())); ++j) {
      int id = flow.e[i][j];
      ee[i][es[id].k] = es[id].c;
    }
  }
  while (go(k, n)) {
    an++;
  }
  printf("%d\n", an);
  return 0;
}
