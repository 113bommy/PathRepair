#include <bits/stdc++.h>
using namespace std;
class fenwick {
  int arr[200005 * 2];

 public:
  fenwick() { memset(arr, 0, sizeof(arr)); }
  void update(int pos, int val) {
    for (int k = pos; k < 200005 * 2; k += (k & -k)) {
      arr[k] += val;
    }
  }
  int get(int pos) {
    int res = 0;
    for (int k = pos; k > 0; k -= (k & -k)) {
      res += arr[k];
    }
    return res;
  }
};
fenwick f = fenwick();
vector<vector<int> > edges(200005);
int dfs_time = 0;
int dfs_in[200005];
int dfs_out[200005];
int dfs_depth[200005];
int val[200005];
void dfs(int pos) {
  dfs_in[pos] = ++dfs_time;
  for (int i = 0; i < edges[pos].size(); i++) {
    if (dfs_in[edges[pos][i]] == 0) {
      dfs_depth[edges[pos][i]] = dfs_depth[pos] + 1;
      dfs(edges[pos][i]);
    }
  }
  dfs_out[pos] = ++dfs_time;
}
int main(int argc, const char* argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &val[i]);
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  dfs(1);
  for (int i = 0, type; i < m; i++) {
    scanf("%d", &type);
    if (type == 1) {
      int x, v;
      scanf("%d %d", &x, &v);
      if (dfs_depth[x] % 2) {
        f.update(dfs_in[x], v);
        f.update(dfs_out[x], -v);
      } else {
        f.update(dfs_in[x], -v);
        f.update(dfs_out[x], v);
      }
    } else {
      int x;
      scanf("%d", &x);
      int res = dfs_depth[x] % 2 ? f.get(dfs_in[x]) : -f.get(dfs_in[x]);
      res += val[x];
      printf("%d\n", res);
    }
  }
  return 0;
}
