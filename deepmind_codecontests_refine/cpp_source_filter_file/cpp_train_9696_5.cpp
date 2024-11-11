#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
char L[2010], R[2010];
int l1, l2, n;
struct Trie {
  int ch[16010][10], tot;
  int sum[16010][2010];
  int get(int x, int c) {
    if (!ch[x][c]) ch[x][c] = ++tot;
    return ch[x][c];
  }
  void insert() {
    if (l1 == l2) {
      int u = 0, v = 0;
      for (int i = 1; i <= l1; i++) {
        if (u == v) {
          for (int j = L[i] - '0' + 1; j <= R[i] - '0' - 1; j++)
            sum[get(u, j)][l1 - i]++;
        } else {
          for (int j = L[i] - '0' + 1; j <= 9; j++) sum[get(u, j)][l1 - i]++;
          for (int j = (i == 1); j <= R[i] - '0' - 1; j++)
            sum[get(u, j)][l1 - i]++;
        }
        u = get(u, L[i] - '0');
        v = get(v, R[i] - '0');
      }
      sum[u][0]++;
      sum[v][0] += (u != v);
    } else {
      int u = 0, v = 0;
      for (int i = 1; i <= l1; i++) {
        for (int j = L[i] - '0' + 1; j <= 9; j++) sum[get(u, j)][l1 - i]++;
        u = get(u, L[i] - '0');
      }
      for (int i = 1; i <= l2; i++) {
        for (int j = (i == 1); j <= R[i] - '0' - 1; j++)
          sum[get(v, j)][l2 - i]++;
        v = get(v, R[i] - '0');
      }
      for (int i = l1 + 1; i < l2; i++)
        for (int j = 1; j <= 9; j++) sum[get(0, j)][i - 1]++;
      sum[u][0]++;
      sum[v][0]++;
    }
  }
  int fail[16010];
  queue<int> q;
  void get_fail() {
    for (int i = 0; i < 10; i++)
      if (ch[0][i]) q.push(ch[0][i]);
    while (q.size()) {
      int now = q.front();
      q.pop();
      for (int i = 0; i <= l2; i++) sum[now][i] += sum[fail[now]][i];
      for (int i = 0; i < 10; i++) {
        if (!ch[now][i])
          ch[now][i] = ch[fail[now]][i];
        else {
          fail[ch[now][i]] = ch[fail[now]][i];
          q.push(ch[now][i]);
        }
      }
    }
    for (int i = 0; i <= tot; i++)
      for (int j = 1; j <= n; j++) sum[i][j] += sum[i][j - 1];
  }
  int f[16010][2010];
  bool ok[16010][2010];
  void Dp() {
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= tot; j++)
        if (f[i - 1][j] >= 0)
          for (int k = 0; k < 10; k++)
            f[i][ch[j][k]] =
                max(f[i][ch[j][k]], f[i - 1][j] + sum[ch[j][k]][n - i]);
    int ans = 0;
    for (int i = 0; i <= tot; i++) ans = max(ans, f[n][i]);
    printf("%d\n", ans);
    for (int i = 0; i <= tot; i++)
      if (f[n][i] == ans) ok[n][i] = 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j <= tot; j++) {
        for (int k = 0; k < 10; k++) {
          if (ok[i + 1][ch[j][k]] &&
              f[i][j] + sum[ch[j][k]][n - i - 1] == f[i + 1][ch[j][k]])
            ok[i][j] = 1;
        }
      }
    }
    int u = 0;
    for (int i = 1; i <= n; i++) {
      for (int k = 0; k < 10; k++) {
        if (ok[i][ch[u][k]] &&
            f[i - 1][u] + sum[ch[u][k]][n - i] == f[i][ch[u][k]]) {
          printf("%d", k);
          u = ch[u][k];
          break;
        }
      }
    }
    puts("");
  }
} T;
int main() {
  scanf("%s", L + 1);
  l1 = strlen(L + 1);
  scanf("%s", R + 1);
  l2 = strlen(R + 1);
  n = read();
  T.insert();
  T.get_fail();
  T.Dp();
  return 0;
}
