#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > Q;
int N, M, A[100005], B[100005], a[100005], b[100005], c[100005], s[100005];
vector<int> e[100005], ee[100005], bg[100005];
void init() {
  scanf("%d%d", &M, &N);
  for (int i = 1, x, y; i <= M; i++) {
    scanf("%d%d", &a[i], &x), bg[a[i]].push_back(i);
    for (; x; x--) {
      scanf("%d", &y);
      if (y == -1)
        b[i]++;
      else
        e[i].push_back(y), ee[y].push_back(i);
    }
    c[i] = e[i].size(), s[i] = b[i];
  }
}
int dfs(int u) {
  if (s[u]) return B[u] = -2;
  if (B[u]) return B[u];
  s[u] = 1;
  for (int i : bg[u])
    if (!c[i]) {
      int w = b[i];
      for (int j : e[i]) {
        int x = dfs(j);
        if (x == -2) return s[u] = 0, B[u] = x;
        w = min(w + x, 314000000);
      }
      B[u] = max(B[u], w);
    }
  return s[u] = 0, B[u];
}
void doit() {
  memset(A, -1, sizeof(A));
  for (int i = 1; i <= M; i++)
    if (!c[i]) Q.push(pair<int, int>(-b[i], a[i]));
  for (int x, y; !Q.empty();) {
    tie(x, y) = Q.top(), Q.pop();
    if (A[y] > -1) continue;
    A[y] = -x;
    for (int i : ee[y]) {
      c[i]--, s[i] = min(s[i] + A[y], 314000000);
      if (!c[i]) Q.push(pair<int, int>(-s[i], a[i]));
    }
  }
  memset(c, 0, sizeof(c));
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= M; i++)
    for (int j : e[i])
      if (A[j] == -1) c[i] = 1;
  for (int i = 1; i <= N; i++)
    if (A[i] > -1)
      dfs(i);
    else
      B[i] = -1;
  for (int i = 1; i <= N; i++) printf("%d %d\n", A[i], B[i]);
}
int main() {
  init();
  doit();
  return 0;
}
