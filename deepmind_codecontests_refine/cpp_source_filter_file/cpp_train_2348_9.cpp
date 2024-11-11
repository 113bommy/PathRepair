#include <bits/stdc++.h>
using namespace std;
int n, m, vis[100010], app[100010];
vector<int> vec[100010];
int A[100010][2];
int abs(int a) { return a > 0 ? a : -a; }
int head[100010], cnt_li;
struct LI {
  int la, v;
} li[100010 << 1];
int add(int a, int b) {
  li[++cnt_li] = (LI){head[a], b};
  head[a] = cnt_li;
}
int q[100010], cnt_q;
int dfs(int u) {
  q[++cnt_q] = u;
  vis[u] = 1;
  for (int e = head[u], v = li[e].v; e; e = li[e].la, v = li[e].v)
    if (!vis[v]) {
      if (abs(A[v][1]) == abs(A[u][1])) swap(A[v][0], A[v][1]);
      if (abs(A[v][0]) == abs(A[u][1])) dfs(v);
    }
}
int ans[2];
int f[100010][2][2];
int T[2], t[2];
int main() {
  scanf("%d%d", &n, &m);
  ans[0] = 1;
  for (int i = 1, k; i <= n; ++i) {
    scanf("%d%d", &k, &A[i][0]);
    if (k == 2) scanf("%d", &A[i][1]);
    ++app[abs(A[i][0])], ++app[abs(A[i][1])];
    if (abs(A[i][0]) == abs(A[i][1])) {
      vis[i] = 1;
      if (A[i][0] == A[i][1])
        ans[0] = ans[1] = (ans[0] + ans[1]) % 1000000007;
      else
        swap(ans[0], ans[1]), ans[0] = ans[0] * 2 % 1000000007,
                              ans[1] = ans[1] * 2 % 1000000007;
      continue;
    }
    vec[abs(A[i][0])].push_back(i);
    vec[abs(A[i][1])].push_back(i);
  }
  for (int i = 1; i <= m; ++i)
    if (vec[i].size() == 2) {
      int a = vec[i][0], b = vec[i][1];
      add(a, b), add(b, a);
    }
  for (int u = 1; u <= n; ++u)
    if (!vis[u] &&
        (A[u][1] == 0 || app[abs(A[u][0])] == 1 || app[abs(A[u][1])] == 1)) {
      if (!A[u][1]) A[u][1] = A[u][0];
      if (app[A[u][1]] == 1) swap(A[u][0], A[u][1]);
      cnt_q = 0;
      dfs(u);
      for (int i = 1; i <= cnt_q; ++i)
        for (int a = 0; a < 2; ++a)
          for (int b = 0; b < 2; ++b) f[i][a][b] = 0;
      for (int a = 0; a < 1 + (A[u][0] != A[u][1]); ++a) {
        for (int b = 0; b < 2; ++b) {
          f[1][b][a | (b == 0 && A[u][1] < 0 || b == 1 && A[u][1] > 0)]++;
        }
      }
      for (int c = 2; c <= cnt_q; ++c) {
        int i = q[c];
        for (int a = 0; a < 2; ++a) {
          for (int b = 0; b < 2; ++b)
            for (int t = 0; t < 2; ++t) {
              int fg = 0;
              if (a == 0 && A[i][0] < 0) fg = 1;
              if (a == 1 && A[i][0] > 0) fg = 1;
              if (b == 0 && A[i][1] < 0) fg = 1;
              if (b == 1 && A[i][1] > 0) fg = 1;
              (f[c][b][(t + fg) % 2] += f[c - 1][a][t]) %= 1000000007;
            }
        }
      }
      t[0] = f[cnt_q][0][0], t[1] = f[cnt_q][0][1];
      if (A[q[cnt_q]][1]) t[0] += f[cnt_q][1][0], t[1] += f[cnt_q][1][1];
      if (cnt_q == 1) {
        if (A[u][0] == A[u][1])
          t[0] = t[1] = 1;
        else
          t[0] = 1, t[1] = 3;
      }
      T[0] = (long long)ans[0] * t[0] % 1000000007 +
             (long long)ans[1] * t[1] % 1000000007;
      T[1] = (long long)ans[0] * t[1] % 1000000007 +
             (long long)ans[1] * t[0] % 1000000007;
      ans[0] = T[0] % 1000000007, ans[1] = T[1] % 1000000007;
    }
  for (int u = 1; u <= n; ++u)
    if (!vis[u]) {
      cnt_q = 0;
      dfs(u);
      for (int i = 1; i <= cnt_q; ++i)
        for (int a = 0; a < 2; ++a)
          for (int b = 0; b < 2; ++b) f[i][a][b] = 0;
      f[1][0][A[u][1] < 0 || A[u][0] < 0] = 1;
      f[1][1][A[u][1] > 0 || A[u][0] < 0] = 1;
      for (int c = 2; c <= cnt_q; ++c) {
        int i = q[c];
        for (int a = 0; a < 2; ++a) {
          for (int b = 0; b < 2; ++b)
            for (int t = 0; t < 2; ++t) {
              int fg = 0;
              if (a == 0 && A[i][0] < 0) fg = 1;
              if (a == 1 && A[i][0] > 0) fg = 1;
              if (b == 0 && A[i][1] < 0) fg = 1;
              if (b == 1 && A[i][1] > 0) fg = 1;
              (f[c][b][(t + fg) % 2] += f[c - 1][a][t]) %= 1000000007;
            }
        }
      }
      t[0] = f[cnt_q][0][0];
      t[1] = f[cnt_q][0][1];
      for (int i = 1; i <= cnt_q; ++i)
        for (int a = 0; a < 2; ++a)
          for (int b = 0; b < 2; ++b) f[i][a][b] = 0;
      f[1][0][A[u][1] < 0 || A[u][0] > 0] = 1;
      f[1][1][A[u][1] > 0 || A[u][0] > 0] = 1;
      for (int c = 2; c <= cnt_q; ++c) {
        int i = q[c];
        for (int a = 0; a < 2; ++a) {
          for (int b = 0; b < 2; ++b)
            for (int t = 0; t < 2; ++t) {
              int fg = 0;
              if (a == 0 && A[i][0] < 0) fg = 1;
              if (a == 1 && A[i][0] > 0) fg = 1;
              if (b == 0 && A[i][1] < 0) fg = 1;
              if (b == 1 && A[i][1] > 0) fg = 1;
              (f[c][b][(t + fg) % 2] += f[c - 1][a][t]) %= 1000000007;
            }
        }
      }
      t[0] += f[cnt_q][1][0];
      t[1] += f[cnt_q][1][1];
      T[0] = (long long)ans[0] * t[0] % 1000000007 +
             (long long)ans[1] * t[1] % 1000000007;
      T[1] = (long long)ans[0] * t[1] % 1000000007 +
             (long long)ans[1] * t[0] % 1000000007;
      ans[0] = T[0] % 1000000007, ans[1] = T[1] % 1000000007;
    }
  for (int i = 1; i <= m; ++i)
    if (!app[i]) ans[1] = ans[1] * 2 % 1000000007;
  printf("%d\n", ans[1]);
  return 0;
}
