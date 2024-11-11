#include <bits/stdc++.h>
int n, m, s;
int pos[15][2], map[33][33], num[7][7], out[33][33];
char str[33][33];
bool ok[33][33], use[15];
__inline bool check() {
  bool use[29];
  memset(use, 0, sizeof(use));
  memset(ok, 0, sizeof(ok));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (ok[i][j] || str[i][j] == '.') continue;
      if (str[i][j] == str[i][j + 1]) {
        ok[i][j + 1] = 1;
        int t1 = map[i][j], t2 = map[i][j + 1];
        if (t1 > t2) t1 ^= t2, t2 ^= t1, t1 ^= t2;
        if (use[num[t1][t2]]) return 0;
        use[num[t1][t2]] = 1;
      } else {
        ok[i + 1][j] = 1;
        int t1 = map[i][j], t2 = map[i + 1][j];
        if (t1 > t2) t1 ^= t2, t2 ^= t1, t1 ^= t2;
        if (use[num[t1][t2]]) return 0;
        use[num[t1][t2]] = 1;
      }
    }
  memcpy(out, map, sizeof(out));
  return 1;
}
void search(int now, int t) {
  if (now == 7) {
    if (check()) s++;
    return;
  }
  while (use[t]) t++;
  map[pos[t][0]][pos[t][1]] = map[pos[t][0]][pos[t][1] + 1] =
      map[pos[t][0] + 1][pos[t][1]] = map[pos[t][0] + 1][pos[t][1] + 1] = now;
  use[t] = 1;
  for (int i = t + 1; i <= 14; i++) {
    if (use[i]) continue;
    map[pos[i][0]][pos[i][1]] = map[pos[i][0]][pos[i][1] + 1] =
        map[pos[i][0] + 1][pos[i][1]] = map[pos[i][0] + 1][pos[i][1] + 1] = now;
    use[i] = 1;
    if (i == t + 1)
      search(now + 1, t + 2);
    else
      search(now + 1, t + 1);
    use[i] = 0;
  }
  use[t] = 0;
}
int main() {
  scanf("%d%d ", &n, &m);
  for (int i = 1; i <= n; i++) gets(str[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (str[i][j] == '.' || ok[i][j]) continue;
      s++;
      pos[s][0] = i;
      pos[s][1] = j;
      ok[i][j] = ok[i + 1][j] = ok[i][j + 1] = ok[i + 1][j + 1] = 1;
    }
  s = 0;
  for (int i = 0; i <= 6; i++)
    for (int j = i; j <= 6; j++) num[i][j] = ++s;
  s = 0;
  search(0, 1);
  printf("%d\n", s * 5040);
  if (s)
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (str[i][j] == '.')
          printf(".");
        else
          printf("%d", map[i][j]);
      }
      printf("\n");
    }
  return 0;
}
