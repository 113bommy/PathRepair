#include <bits/stdc++.h>
using namespace std;
int Num;
const int inf = 0x3f3f3f3f;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int A[22][22];
int B[22][22];
int n, m;
int w[22][22];
int c[22][22];
int visa[42];
int visb[42];
int laba[42];
int labb[42];
int mat[42];
int tim;
int ans;
bool extend(int x) {
  if (!x) return 1;
  visa[x] = tim;
  for (int i = 1; i <= n; i++) {
    if (visb[i] != tim && laba[x] + labb[i] == w[x][i]) {
      visb[i] = tim;
      if (extend(mat[i])) {
        mat[i] = x;
        return 1;
      }
    }
  }
  return 0;
}
void change() {
  int delta = inf;
  for (int i = 1; i <= n; i++)
    if (visa[i] == tim) {
      for (int j = 1; j <= n; j++) {
        if (visb[j] != tim) {
          delta = min(delta, laba[i] + labb[j] - w[i][j]);
        }
      }
    }
  for (int i = 1; i <= n; i++)
    if (visa[i] == tim) laba[i] -= delta;
  for (int i = 1; i <= n; i++)
    if (visb[i] == tim) labb[i] += delta;
}
int km() {
  for (int i = 1; i <= n; i++) visa[i] = visb[i] = mat[i] = 0;
  for (int i = 1; i <= n; i++) laba[i] = w[i][0], labb[i] = 0;
  tim = 0;
  for (int i = 1; i <= n; i++) {
    for (;;) {
      ++tim;
      if (extend(i)) break;
      change();
    }
  }
  int re = 0;
  for (int i = 1; i <= n; i++) re += w[mat[i]][i];
  return re;
}
int tot = 0;
void dfs(int x, int cnt) {
  int now = km();
  if (now <= ans) return;
  if (x == n) {
    ans = now;
    return;
  }
  tot++;
  if (tot > 50000) return;
  x++;
  if (m - cnt < n - x + 1) {
    for (int i = 0; i <= n; i++) w[x][i] = A[x][i];
    dfs(x, cnt);
  }
  if (cnt < m) {
    for (int i = 0; i <= n; i++) w[x][i] = B[x][i];
    dfs(x, cnt + 1);
  }
  for (int i = 0; i <= n; i++) w[x][i] = c[x][i];
}
int main() {
  n = read();
  m = n / 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      A[i][j] = read();
      A[i][0] = max(A[i][j], A[i][0]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      B[i][j] = read();
      B[i][0] = max(B[i][0], B[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      w[i][j] = c[i][j] = max(A[i][j], B[i][j]);
      w[i][0] = c[i][0] = max(w[i][0], c[i][j]);
    }
  }
  dfs(0, 0);
  cout << ans << endl;
}
