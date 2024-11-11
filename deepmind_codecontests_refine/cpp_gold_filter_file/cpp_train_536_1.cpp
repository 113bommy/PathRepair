#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int head[N], nxt[N * 2], v[N * 2], sz[N], n, ptr;
void add_edge(int uu, int vv) {
  v[ptr] = vv;
  nxt[ptr] = head[uu];
  head[uu] = ptr++;
}
void dfs1(int pos, int fa) {
  sz[pos] = 1;
  for (int i = head[pos]; i != -1; i = nxt[i]) {
    if (v[i] == fa) continue;
    dfs1(v[i], pos);
    sz[pos] += sz[v[i]];
  }
}
void dfs2(int pos, int fa, int w) {
  int ww = w;
  for (int i = head[pos]; i != -1; i = nxt[i])
    if (v[i] != fa) {
      printf("%d %d %d\n", pos, v[i], ww);
      dfs2(v[i], pos, w);
      ww += w * sz[v[i]];
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  memset(head, -1, sizeof(head));
  memset(nxt, -1, sizeof(nxt));
  for (int i = 1; i < n; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    add_edge(t1, t2);
    add_edge(t2, t1);
  }
  int target = 2 * n * n / 9;
  for (int rt = 1; rt <= n; rt++) {
    dfs1(rt, 0);
    vector<int> tmp;
    for (int i = head[rt]; i != -1; i = nxt[i]) tmp.push_back(v[i]);
    sort(tmp.begin(), tmp.end(), [](int a, int b) { return sz[a] < sz[b]; });
    int sum = 0;
    for (int i = 0; i < tmp.size(); i++) {
      sum += sz[tmp[i]];
      if ((sum + 1) * (n - sum - 1) >= target) {
        int cur = 1;
        for (int j = 0; j <= i; j++) {
          printf("%d %d %d\n", rt, tmp[j], cur);
          dfs2(tmp[j], rt, 1);
          cur += sz[tmp[j]];
        }
        cur = sum + 1;
        for (int j = i + 1; j < tmp.size(); j++) {
          printf("%d %d %d\n", rt, tmp[j], cur);
          dfs2(tmp[j], rt, sum + 1);
          cur += sz[tmp[j]] * (sum + 1);
        }
        return 0;
      }
    }
  }
  return 0;
}
