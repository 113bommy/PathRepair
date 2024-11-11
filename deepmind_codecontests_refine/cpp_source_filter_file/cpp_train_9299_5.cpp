#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int tri[N][26], p[N], f[N], q[N], k;
void build(char s[], int x) {
  int c = 0, i, j;
  for (i = 0; s[i]; i++) {
    j = s[i] - 'a';
    if (!tri[c][j]) tri[c][j] = ++k;
    c = tri[c][j];
  }
  f[x] = c;
}
void bfs() {
  int i, t, w;
  p[0] = -1;
  q[0] = 0;
  t = w = 0;
  while (t <= w) {
    int fr = q[t++], fail = p[fr];
    for (i = 0; i < 26; i++) {
      if (tri[fr][i]) {
        if (fail != -1) {
          p[tri[fr][i]] = tri[fail][i];
        }
        q[++w] = tri[fr][i];
      } else {
        if (fail != -1) tri[fr][i] = tri[fail][i];
      }
    }
  }
}
char str[N];
vector<int> E[N];
int c[N], L[N], R[N];
int lowbit(int x) { return x & (-x); }
int getsum(int x) {
  int r = 0;
  while (x > 0) {
    r += c[x];
    x -= lowbit(x);
  }
  return r;
}
void up(int x, int v) {
  while (x < N) {
    c[x] += v;
    x += lowbit(x);
  }
}
void dfs(int x) {
  L[x] = R[x] = k++;
  for (int i = E[x].size() - 1; i >= 0; i--) {
    int j = E[x][i];
    dfs(j);
    if (R[x] < R[j]) R[x] = R[j];
  }
}
int get(char s[]) {
  int c = 0, i, r = 0;
  for (i = 0; s[i]; i++) {
    c = tri[c][s[i] - 'a'];
    if (c) r += getsum(L[c]);
  }
  return r;
}
bool u[N];
int main() {
  int n, m, i;
  scanf("%d%d", &m, &n);
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    build(str, i);
  }
  bfs();
  for (i = 1; i <= k; i++) {
    E[p[i]].push_back(i);
  }
  k = 0;
  dfs(0);
  for (i = 1; i < k; i++) {
    up(L[i], 1);
    up(R[i] + 1, -1);
  }
  memset(u, true, sizeof(u));
  while (m--) {
    scanf("%s", str);
    if (str[0] == '?') {
      printf("%d\n", get(str + 1));
    } else if (str[0] == '-') {
      int v = 0;
      for (i = 1; str[i]; i++) v = v * 10 + str[i] - '0';
      if (u[v]) {
        u[v] = false;
        int id = f[v - 1];
        up(L[id], -1);
        up(R[id] + 1, 1);
      }
    } else {
      int v = 0;
      for (i = 1; str[i]; i++) v = v * 10 + str[i] - '0';
      if (!u[v]) {
        u[v] = true;
        int id = f[v - 1];
        up(L[id], 1);
        up(R[id] + 1, -1);
      }
    }
  }
  return 0;
}
