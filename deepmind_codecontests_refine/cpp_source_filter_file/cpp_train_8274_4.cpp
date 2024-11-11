#include <bits/stdc++.h>
using namespace std;
int n, m, P, a[105][105], fa[105 * 105], cnt, id[105][105], tg[105 * 105];
char s[105];
int pw(int x, int y, int P) {
  int ans = 1;
  for (; y; y >>= 1, x = (long long)x * x % P)
    if (y & 1) ans = (long long)ans * x % P;
  return ans;
}
int inv(int x) { return pw(x, P - 2, P); }
struct T {
  int sz, a[205][205];
  void link(int x, int y) {
    a[x][y]--;
    a[y][x]--;
    a[x][x]++;
    a[y][y]++;
  }
  void out() {
    for (int i = 1; i <= sz; i++) {
      for (int j = 1; j <= sz; j++) printf("%d ", a[i][j]);
      puts("");
    }
  }
  int work() {
    sz--;
    if (!sz) return 1;
    for (int i = 1; i <= sz; i++)
      for (int j = 1; j <= sz; j++) a[i][j] = (a[i][j] % P + P) % P;
    int A = 0;
    for (int i = 1; i <= sz; i++) {
      int tmp = i;
      for (int j = i + 1; j <= sz; j++)
        if (a[j][i]) tmp = j;
      if (!a[tmp][i]) return 0;
      if ((tmp ^ i) & i) A ^= 1;
      for (int j = 1; j <= sz; j++) swap(a[i][j], a[tmp][j]);
      int tp = inv(a[i][i]);
      for (int j = i + 1; j <= sz; j++) {
        int t = (long long)a[j][i] * tp % P;
        for (int k = 1; k <= sz; k++)
          a[j][k] = (a[j][k] - (long long)a[i][k] * t % P + P) % P;
      }
    }
    int Ans = 1;
    for (int i = 1; i <= sz; i++) Ans = (long long)Ans * a[i][i] % P;
    return A ? (P - Ans) % P : Ans;
  }
} M1, M2;
void biu() {
  puts("0");
  exit(0);
}
int Get(int x) { return fa[x] == x ? x : fa[x] = Get(fa[x]); }
int main() {
  scanf("%d%d%d", &n, &m, &P);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++)
      a[i][j] = s[j] == '*' ? 0 : s[j] == '/' ? 1 : 2;
  }
  for (int i = 1; i <= n + 1; i++)
    for (int j = 1; j <= m + 1; j++) fa[id[i][j] = ++cnt] = cnt;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) {
        int u = Get(id[i + 1][j]), v = Get(id[i][j + 1]);
        if (u == v) biu();
        fa[u] = v;
      } else if (a[i][j] == 2) {
        int u = Get(id[i][j]), v = Get(id[i + 1][j + 1]);
        if (u == v) biu();
        fa[u] = v;
      }
    }
  }
  for (int i = 1; i <= n + 1; i++)
    for (int j = 1; j <= m + 1; j++)
      if (fa[id[i][j]] == id[i][j]) {
        if ((i ^ j) & 1)
          tg[id[i][j]] = ++M1.sz;
        else
          tg[id[i][j]] = ++M2.sz;
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        if ((i ^ j) & 1) {
          M1.link(tg[Get(id[i][j])], tg[Get(id[i + 1][j + 1])]);
          M2.link(tg[Get(id[i][j + 1])], tg[Get(id[i + 1][j])]);
        } else {
          M2.link(tg[Get(id[i][j])], tg[Get(id[i + 1][j + 1])]);
          M1.link(tg[Get(id[i][j + 1])], tg[Get(id[i + 1][j])]);
        }
      }
    }
  printf("%d\n", (M1.work() + M2.work()) % P);
}
