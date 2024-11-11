#include <bits/stdc++.h>
using namespace std;
char s[2005];
int n, c[2005][2005], ans = 0x3f3f3f3f, was, ot[2005];
bool chk() {
  static int ar[2005];
  int sum = 0;
  for (int i = (1), LIM = (n); i <= LIM; i++) ar[i] = ot[i], sum += ot[i];
  sort(ar + 1, ar + 1 + n);
  int sm = 0;
  for (int i = (1), LIM = (n - 1); i <= LIM; i++) {
    sm += ar[i];
    if (sm == i * (i - 1) / 2) return 0;
  }
  return 1;
}
void dfs(int u, int s) {
  if (u == n + 1) {
    if (chk()) {
      if (ans > s) ans = s, was = 0;
      if (ans == s) was++;
    }
    return;
  }
  dfs(u + 1, s);
  for (int i = (1), LIM = (n); i <= LIM; i++)
    if (c[u][i])
      ot[u]--, ot[i]++;
    else
      ot[u]++, ot[i]--;
  for (int i = (1), LIM = (n); i <= LIM; i++) swap(c[i][u], c[u][i]);
  dfs(u + 1, s + 1);
  for (int i = (1), LIM = (n); i <= LIM; i++)
    if (c[u][i])
      ot[u]--, ot[i]++;
    else
      ot[u]++, ot[i]--;
  for (int i = (1), LIM = (n); i <= LIM; i++) swap(c[i][u], c[u][i]);
}
int main() {
  scanf("%d", &n);
  for (int i = (1), LIM = (n); i <= LIM; i++) {
    scanf("%s", s + 1);
    for (int j = (1), LIM = (n); j <= LIM; j++)
      c[i][j] = (s[j] == '1'), ot[i] += c[i][j];
  }
  if (n <= 6) {
    dfs(1, 0);
    if (ans == 0x3f3f3f3f)
      puts("-1");
    else {
      for (int i = (1), LIM = (ans); i <= LIM; i++)
        was = 1ll * was * i % 998244353;
      printf("%d %d\n", ans, was);
    }
    return 0;
  } else {
    if (chk()) {
      puts("0 1");
      return 0;
    }
    for (int u = (1), LIM = (n); u <= LIM; u++) {
      for (int i = (1), LIM = (n); i <= LIM; i++)
        if (c[u][i])
          ot[u]--, ot[i]++;
        else
          ot[u]++, ot[i]--;
      for (int i = (1), LIM = (n); i <= LIM; i++) swap(c[i][u], c[u][i]);
      if (chk()) was++;
      for (int i = (1), LIM = (n); i <= LIM; i++)
        if (c[u][i])
          ot[u]--, ot[i]++;
        else
          ot[u]++, ot[i]--;
      for (int i = (1), LIM = (n); i <= LIM; i++) swap(c[i][u], c[u][i]);
    }
    printf("%d %d\n", ans, was);
  }
}
