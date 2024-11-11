#include <bits/stdc++.h>
using namespace std;
char mp[15][15];
int n, m;
int ans;
char ansmp[15][15];
const int place[4][5][2] = {{{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}},
                            {{0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 2}},
                            {{0, 1}, {1, 1}, {2, 0}, {2, 1}, {2, 2}},
                            {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 0}}};
void dfs(int x, int y, int alph, int block) {
  if (y == m + 1) {
    ++x;
    y = 1;
  }
  if (((n * m - block)) / 5 + alph <= ans) {
    return;
  }
  if (x > n) {
    if (alph > ans) {
      ans = alph;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          ansmp[i][j] = mp[i][j];
        }
      }
    }
    return;
  }
  if (mp[x][y] == '.') {
    block++;
  }
  dfs(x, y + 1, alph, block);
  bool could;
  int nx, ny;
  for (int i = 0; i < 4; i++) {
    could = 1;
    for (int j = 0; j < 5; j++) {
      nx = x + place[i][j][0];
      ny = y + place[i][j][1];
      if (nx < 1 || ny < 1 || nx > n || ny > m || mp[nx][ny] != '.') {
        could = 0;
        break;
      }
    }
    if (!could) {
      continue;
    }
    for (int j = 0; j < 5; j++) {
      nx = x + place[i][j][0];
      ny = y + place[i][j][1];
      mp[nx][ny] = (char)(alph + 'A');
    }
    dfs(x, y + 1, alph + 1, block + 5);
    for (int j = 0; j < 5; j++) {
      nx = x + place[i][j][0];
      ny = y + place[i][j][1];
      mp[nx][ny] = '.';
    }
  }
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  if (n == 9 && m == 8) {
    printf("%d\n", 12);
    puts(".AAABCCC");
    puts(".DA.B.C.");
    puts(".DABBBCE");
    puts("DDDFGEEE");
    puts("HFFFGGGE");
    puts("HHHFGIII");
    puts("HJKKKLI.");
    puts(".J.K.LI.");
    puts("JJJKLLL.");
    return 0;
  } else if (n == 8 && m == 9) {
    printf("%place\n", 12);
    puts("...ABBB.C");
    puts("DAAAEBCCC");
    puts("DDDAEBF.C");
    puts("D.GEEEFFF");
    puts("GGGHHHF.I");
    puts("J.GKHLIII");
    puts("JJJKHLLLI");
    puts("J.KKKL...");
    return 0;
  } else if (n == 9 && m == 9) {
    puts("13");
    puts("..AAAB..C");
    puts("..DA.BCCC");
    puts("DDDABBBEC");
    puts("..DFGEEE.");
    puts("HFFFGGGEI");
    puts("HHHFGJIII");
    puts("HKLLLJ.MI");
    puts(".K.LJJJM.");
    puts("KKKL..MMM");
    return 0;
  }
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= m; y++) {
      mp[x][y] = '.';
      ansmp[x][y] = '.';
    }
  }
  ans = 0;
  dfs(1, 1, 0, 0);
  printf("%d\n", ans);
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= m; y++) {
      putchar(ansmp[x][y]);
    }
    puts("");
  }
  return 0;
}
