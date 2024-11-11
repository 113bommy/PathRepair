#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
int len = 0, n, K, T;
char ch[600];
int son[N], s[N][26], d[N], v[N], u[N];
int num = 0, a[N], f[6100][1100];
void _ins() {
  int L = strlen(ch + 1), now = 0;
  for (int i = 1, x; i <= L; ++i) {
    x = ch[i] - 'a';
    ++son[now];
    if (s[now][x] == 0) {
      ++v[now];
      ++len;
      memset(s[len], 0, sizeof(s[len]));
      s[now][x] = len, a[len] = v[len] = son[len] = 0;
      d[len] = d[now] + 1;
      u[len] = now;
    }
    now = s[now][x];
  }
  ++son[now];
}
int b[N];
void bfs() {
  b[1] = 0;
  int h, now;
  for (h = 1, T = 1; h <= T; ++h) {
    now = b[h];
    for (int i = 0; i <= 25; ++i)
      if (s[now][i] > 0) {
        b[++T] = s[now][i];
        if (son[b[T]] < 2) --T;
      }
  }
}
void Gans() {
  d[0] = 1;
  for (int p, j = T, now; j > 0; --j) {
    now = b[j];
    if (a[now] != 0) continue;
    a[now] = (++num);
    memset(f[num], 0, sizeof(f[num]));
    for (int i = 0; i <= 25; ++i)
      if (s[now][i] > 0) {
        p = s[now][i];
        if (a[p] <= 0) continue;
        for (int l = son[now]; l >= 0; --l)
          for (int k = min(son[p], son[now] - l); k >= 0; --k)
            if (f[num][l + k] < f[num][l] + f[a[p]][k])
              f[num][l + k] = f[num][l] + f[a[p]][k];
      }
    if (now != 0)
      for (int i = 1; i <= son[now]; ++i) f[num][i] += i * (i - 1) / 2;
    if (now != 0 && son[u[now]] == son[now]) {
      int k = now;
      while (k != 0 && son[u[k]] == son[now]) k = u[k], a[k] = -1;
      a[k] = (++num);
      for (int i = 0; i <= son[k]; ++i)
        f[num][i] = f[a[now]][i] + i * (i - 1) / 2 * (d[now] - d[k]);
    }
  }
  int ans = 0;
  for (int i = 0; i <= K; ++i)
    if (f[a[0]][i] > ans) ans = f[a[0]][i];
  cout << ans << endl;
}
int main() {
  memset(s[0], 0, sizeof(s[0])), a[0] = d[0] = son[0] = v[0] = 0;
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; ++i) scanf("%s", ch + 1), _ins();
  bfs();
  Gans();
  return 0;
}
