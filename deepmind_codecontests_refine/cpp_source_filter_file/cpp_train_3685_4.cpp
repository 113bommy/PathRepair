#include <bits/stdc++.h>
using namespace std;
class uftree {
 public:
  int n;
  vector<int> val;
  uftree(int n_) : n(n_), val(n_, -1) {}
  int root(int x) { return (val[x] < 0) ? x : (val[x] = root(val[x])); }
  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    val[x] += val[y];
    val[y] = x;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int independent(int nn) {
    int ret = 0;
    for (int i = 0; i < nn; i++)
      if (val[i] < 0) ret++;
    return ret;
  }
};
struct task {
  int s, t, d;
};
vector<task> ans;
int n, e, v, from, to;
int a[301];
int b[301];
int sum[301];
int tube[301][301];
bool used[301];
int prevv[301];
bool dfs(int s, int t, vector<int>& path) {
  if (s == t) {
    path.push_back(s);
    return true;
  }
  used[s] = true;
  for (int i = 0; i < n; i++) {
    if (!used[i] && tube[s][i] == 1) {
      if (dfs(i, t, path)) {
        path.push_back(s);
        return true;
      }
    }
  }
  return false;
}
void pour(int i, int j, int d, vector<int>& path) {
  if (i == j) return;
  int s = path[j - 1];
  int t = path[j];
  int cap = min(d, a[s]);
  if (cap > 0) {
    a[s] -= cap;
    a[t] += cap;
    task tsk = {s, t, cap};
    ans.push_back(tsk);
  }
  pour(i, j - 1, d, path);
  int rest = d - cap;
  if (rest > 0) {
    a[s] -= rest;
    a[t] += rest;
    task tsk = {s, t, rest};
    ans.push_back(tsk);
  }
}
bool solve() {
  ans.clear();
  uftree uf(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (tube[i][j] == 1) {
        uf.merge(i, j);
      }
    }
  }
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i < n; i++) {
    sum[uf.root(i)] += a[i] - b[i];
  }
  for (int i = 0; i < n; i++) {
    if (sum[i] != 0) return false;
  }
  vector<int> path;
  bool update = true;
  while (update) {
    update = false;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) continue;
      for (int j = 0; j < n; j++) {
        if (!uf.same(i, j) || a[j] == b[j]) continue;
        if ((a[i] < b[i]) ^ (a[j] < b[j])) {
          int s, t, d;
          if (a[i] < b[i]) {
            s = j;
            t = i;
            d = min(b[i] - a[i], a[j] - b[j]);
          } else {
            s = i;
            t = j;
            d = min(a[i] - b[i], b[j] - a[j]);
          }
          memset(used, 0, sizeof(used));
          path.clear();
          dfs(s, t, path);
          reverse((path).begin(), (path).end());
          int len = path.size();
          pour(0, len - 1, d, path);
          update = true;
          goto ex;
        }
      }
    }
  ex:;
  }
  return true;
}
void coding() {
  while (scanf("%d%d%d", &n, &v, &e) != EOF) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", b + i);
    }
    memset(tube, 0, sizeof(tube));
    for (int i = 0; i < e; i++) {
      scanf("%d%d", &from, &to);
      from--;
      to--;
      tube[from][to] = 1;
      tube[to][from] = 1;
    }
    if (!solve()) {
      printf("NO\n");
    } else {
      int sz = (int)(ans).size();
      printf("%d\n", sz);
      for (int i = 0; i < sz; i++) {
        printf("%d %d %d\n", ans[i].s + 1, ans[i].t + 1, ans[i].d);
      }
    }
  }
}
int main() { coding(); }
