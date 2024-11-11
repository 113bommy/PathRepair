#include <bits/stdc++.h>
using namespace std;
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
int n, tot, go[210][26], fa[210], a[210], po[210];
long long l;
char s[210];
struct matrix {
  long long x[210][210];
  long long *operator[](int a) { return x[a]; }
  void clear() { memset(x, 0, sizeof(x)); }
  void reset() {
    memset(x, 0, sizeof(x));
    for (int i = 0; i < 210; ++i) x[i][i] = 1;
  }
} p, A, ans;
matrix operator*(matrix &a, matrix &b) {
  memset(p.x, 128, sizeof(p.x));
  for (int i = 0; i < tot; i++)
    for (int j = 0; j < tot; j++)
      for (int k = 0; k < tot; k++)
        if (a[i][k] >= 0 && b[k][j] >= 0)
          p[i][j] = max(p[i][j], a[i][k] + b[k][j]);
  return p;
}
void build() {
  queue<int> q;
  for (int i = 0; i < 26; ++i)
    if (!go[1][i])
      go[1][i] = 1;
    else {
      fa[go[1][i]] = 1;
      q.push(go[1][i]);
    }
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int i = 0; i < 26; ++i) {
      if (!go[t][i]) {
        go[t][i] = go[fa[t]][i];
      } else {
        fa[go[t][i]] = go[fa[t]][i];
        po[go[t][i]] += po[go[fa[t]][i]];
        q.push(go[t][i]);
      }
    }
  }
}
int main() {
  scanf("%d%lld", &n, &l);
  tot = 1;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    int m = strlen(s + 1);
    int cur = 1;
    for (int i = 1; i <= m; ++i) {
      int x = s[i] - 'a';
      if (!go[cur][x]) go[cur][x] = ++tot;
      cur = go[cur][x];
    }
    po[cur] += a[i];
  }
  build();
  memset(A.x, 128, sizeof(A.x));
  for (int i = 1; i <= tot; ++i) {
    for (int j = 0; j < 26; ++j) {
      A[go[i][j] - 1][i - 1] = po[go[i][j]];
    }
  }
  ans = A;
  l--;
  for (; l; l >>= 1, A = A * A)
    if (l & 1) ans = ans * A;
  long long res = 0;
  for (int i = 0; i < tot; ++i) res = max(res, ans[i][0]);
  printf("%lld\n", res);
  return 0;
}
