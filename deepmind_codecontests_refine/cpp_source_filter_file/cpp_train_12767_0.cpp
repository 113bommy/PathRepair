#include <bits/stdc++.h>
using namespace std;
const int N = 255;
const int inf = 0x7fffffff;
int f[256][2];
char s[256][2][30], st[30];
struct dnode {
  int x, op, d;
  dnode(int x = 0, int op = 0, int d = 0) : x(x), op(op), d(d) {}
  bool operator<(const dnode &A) const {
    if (d != A.d) return d > A.d;
    for (int i = 1; i <= d; i++) {
      if (s[x][op][i] != s[A.x][A.op][i]) return s[x][op][i] > s[A.x][A.op][i];
    }
    return false;
  }
};
bool check(int x, int op) {
  for (int i = 1; i <= f[x][op]; i++) {
    if (st[i] < s[x][op][i]) return true;
    if (st[i] > s[x][op][i]) return false;
  }
  return false;
}
void pre() {
  for (int i = 0; i <= N; i++)
    for (int j = 0; j < 2; j++) f[i][j] = inf;
  f[240][1] = f[204][1] = f[170][1] = 1;
  s[240][1][1] = 'x';
  s[204][1][1] = 'y';
  s[170][1][1] = 'z';
  f[15][1] = f[51][1] = f[85][1] = 2;
  s[15][1][1] = s[51][1][1] = s[85][1][1] = '!';
  s[15][1][2] = 'x';
  s[51][1][2] = 'y';
  s[85][1][2] = 'z';
  priority_queue<dnode> q;
  q.push(dnode(240, 1, 1));
  q.push(dnode(204, 1, 1));
  q.push(dnode(170, 1, 1));
  q.push(dnode(15, 1, 2));
  q.push(dnode(51, 1, 2));
  q.push(dnode(85, 1, 2));
  while (!q.empty()) {
    dnode x = q.top();
    q.pop();
    if (x.d > f[x.x][x.op]) continue;
    if (x.x == 237 && x.op == 0) {
      int uu = 0;
    }
    if (f[x.x][1] >= f[x.x][x.op] + 2) {
      st[1] = '(';
      for (int i = 1; i <= f[x.x][x.op]; i++) st[i + 1] = s[x.x][x.op][i];
      st[f[x.x][x.op] + 2] = ')';
      if (f[x.x][1] > f[x.x][x.op] + 2 || check(x.x, 1)) {
        if (x.x == 18) {
          int uu = 0;
        }
        f[x.x][1] = f[x.x][x.op] + 2;
        for (int i = 1; i <= f[x.x][1]; i++) s[x.x][1][i] = st[i];
        q.push(dnode(x.x, 1, f[x.x][1]));
      }
    }
    if (f[x.x ^ N][1] >= f[x.x][x.op] + 3) {
      int nxt = x.x ^ N;
      st[1] = '!';
      st[2] = '(';
      for (int i = 1; i <= f[x.x][x.op]; i++) st[i + 2] = s[x.x][x.op][i];
      st[f[x.x][x.op] + 3] = ')';
      if (f[nxt][1] > f[x.x][x.op] + 3 || check(nxt, 1)) {
        if (nxt == 18) {
          int uu = 0;
        }
        f[nxt][1] = f[x.x][x.op] + 3;
        for (int i = 1; i <= f[nxt][1]; i++) s[nxt][1][i] = st[i];
        q.push(dnode(nxt, 1, f[nxt][1]));
      }
    }
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j < 2; j++) {
        if (f[i][j] == inf) continue;
        if (f[x.x | i][0] >= f[x.x][x.op] + f[i][j] + 1) {
          int nxt = x.x | i;
          for (int k = 1; k <= f[x.x][x.op]; k++) st[k] = s[x.x][x.op][k];
          st[f[x.x][x.op] + 1] = '|';
          for (int k = 1; k <= f[i][j]; k++)
            st[k + f[x.x][x.op] + 1] = s[i][j][k];
          if (f[nxt][0] > f[x.x][x.op] + f[i][j] + 1 || check(nxt, 0)) {
            f[nxt][0] = f[x.x][x.op] + f[i][j] + 1;
            for (int k = 1; k <= f[nxt][0]; k++) s[nxt][0][k] = st[k];
            q.push(dnode(nxt, 0, f[nxt][0]));
          }
          for (int k = 1; k <= f[i][j]; k++) st[k] = s[i][j][k];
          st[f[i][j] + 1] = '|';
          for (int k = 1; k <= f[x.x][x.op]; k++)
            st[k + f[i][j] + 1] = s[x.x][x.op][k];
          if (check(nxt, 0)) {
            for (int k = 1; k <= f[nxt][0]; k++) s[nxt][0][k] = st[k];
            q.push(dnode(nxt, 0, f[nxt][0]));
          }
        }
        if (x.op && j) {
          if (f[x.x & i][1] >= f[x.x][x.op] + f[i][j] + 1) {
            int nxt = x.x & i;
            for (int k = 1; k <= f[x.x][x.op]; k++) st[k] = s[x.x][x.op][k];
            st[f[x.x][x.op] + 1] = '&';
            for (int k = 1; k <= f[i][j]; k++)
              st[k + f[x.x][x.op] + 1] = s[i][j][k];
            if (nxt == 18) {
              int tt = 0;
            }
            if (f[nxt][1] > f[x.x][x.op] + f[i][j] + 1 || check(nxt, 1)) {
              f[nxt][1] = f[x.x][x.op] + f[i][j] + 1;
              for (int k = 1; k <= f[nxt][1]; k++) s[nxt][1][k] = st[k];
              q.push(dnode(nxt, 1, f[nxt][1]));
            }
            for (int k = 1; k <= f[i][j]; k++) st[k] = s[i][j][k];
            st[f[i][j] + 1] = '&';
            for (int k = 1; k <= f[x.x][x.op]; k++)
              st[k + f[i][j] + 1] = s[x.x][x.op][k];
            if (check(nxt, 1)) {
              if (nxt == 18) {
                int yy = 0;
              }
              for (int k = 1; k <= f[nxt][1]; k++) s[nxt][1][k] = st[k];
              q.push(dnode(nxt, 1, f[nxt][1]));
            }
          }
        }
      }
    }
  }
  for (int i = 0; i <= N; i++) {
    if (f[i][0] >= f[i][1]) {
      for (int j = 1; j <= f[i][1]; j++) st[j] = s[i][1][j];
      if (f[i][0] > f[i][1] || check(i, 0)) {
        f[i][0] = f[i][1];
        for (int j = 1; j <= f[i][0]; j++) s[i][0][j] = st[j];
      }
    }
  }
}
int main() {
  int i, j, k;
  pre();
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", st);
    int ans = 0;
    for (i = 0; i < 8; i++) {
      if (st[i] == '1') ans += 1 << i;
    }
    for (i = 1; i <= f[ans][0]; i++) printf("%c", s[ans][0][i]);
    printf("\n");
  }
  return 0;
}
