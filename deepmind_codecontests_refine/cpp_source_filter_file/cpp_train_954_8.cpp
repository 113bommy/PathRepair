#include <bits/stdc++.h>
using namespace std;
template <class T>
void chkmax(T &a, T b) {
  if (a < b) a = b;
}
const int inf = 0x3f3f3f3f;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
void read(int &x) {
  char c = nc(), b = 1;
  for (; !((c >= '0' && c <= '9') || c == EOF); c = nc())
    if (c == '-') b = -b;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
  x *= b;
}
vector<int> v[200005];
int n;
int mx[200005][4], id[200005][4];
void refresh(int k) {
  int t = 3;
  while (t >= 1 && mx[k][t] > mx[k][t - 1]) {
    swap(mx[k][t], mx[k][t - 1]);
    swap(id[k][t], id[k][t - 1]);
    t--;
  }
}
void dfs(int k, int pa) {
  int son = 0;
  for (auto x : v[k]) {
    if (x == pa) continue;
    dfs(x, k);
    son++;
    mx[k][3] = mx[x][0] + 1, id[k][3] = x;
    refresh(k);
  }
  if (!son) mx[k][0] = 1;
  return;
}
void dfs_up(int k, int pa) {
  if (pa) {
    mx[k][3] = mx[pa][3] + 1;
    if (k == id[pa][0])
      chkmax(mx[k][3], 2 + mx[pa][1]);
    else
      chkmax(mx[k][3], 2 + mx[pa][0]);
  } else
    mx[k][3] = 1;
  for (auto x : v[k]) {
    if (x == pa) continue;
    dfs_up(x, k);
  }
  return;
}
int c[200005];
int d[200005], p[200005];
int BFS(int rt, int n) {
  static queue<int> Q;
  while (!Q.empty()) Q.pop();
  for (int i = 1; i <= n; i++) d[i] = inf;
  d[rt] = p[rt] = 0;
  Q.push(rt);
  int res;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    res = x;
    for (int i = 0; i < v[x].size(); i++) {
      int y = v[x][i];
      if (d[y] < inf) continue;
      d[y] = d[x] + 1;
      p[y] = x;
      Q.push(y);
    }
  }
  return res;
}
int K;
void dfs_col(int k, int p) {
  for (auto x : v[k]) {
    if (x == p) continue;
    if (!c[x]) {
      c[x] = 2 * c[k] - c[p];
      if (c[x] > K) c[x] -= K;
      if (c[x] <= 0) c[x] += K;
    }
    dfs_col(x, k);
  }
  return;
}
int main() {
  read(n), read(K);
  for (int i = 1; i < n; i++) {
    int x, y;
    read(x), read(y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  dfs_up(1, 0);
  for (int i = 1; i <= n; i++) refresh(i);
  bool flag = 0;
  if (K > 2) {
    for (int i = 1; i <= n; i++) {
      if (mx[i][2] <= 1) continue;
      if (mx[i][2] + mx[i][1] - 1 >= K) flag = 1;
    }
  }
  if (flag) {
    puts("No");
    return 0;
  }
  puts("Yes");
  int st = BFS(1, n);
  int ed = BFS(st, n);
  vector<int> P;
  int cur = ed;
  while (cur) {
    P.push_back(cur);
    cur = p[cur];
  }
  for (int i = 0; i < P.size(); i++) c[P[i]] = i % K + 1;
  int sz = P.size() - 1;
  if (n > 2) {
    int k = sz >> 1;
    dfs_col(P[k], P[k + 1]);
    k = sz + 1 >> 1;
    dfs_col(P[k], P[k - 1]);
  }
  for (int i = 1; i <= n; i++) {
    c[i] = max(c[i], 1);
    printf("%d ", c[i]);
  }
  return 0;
}
