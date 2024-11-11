#include <bits/stdc++.h>
using namespace std;
struct aa {
  int h2, h5;
  string s;
} ch[2][1002][2];
int c2[1002][1002];
int c5[1002][1002];
void copy(int i, int j) {
  ch[i & 1][j][1].h2 = ch[i & 1][j][0].h2;
  ch[i & 1][j][1].h5 = ch[i & 1][j][0].h5;
  ch[i & 1][j][1].s = ch[i & 1][j][0].s;
}
int main() {
  int n, spx = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int tmp;
      scanf("%d", &tmp);
      if (!tmp && !spx) spx = i;
      while (tmp && tmp % 2 == 0) {
        tmp /= 2;
        c2[i][j]++;
      }
      while (tmp && tmp % 5 == 0) {
        tmp /= 5;
        c5[i][j]++;
      }
    }
  }
  ch[1][1][0].h2 = c2[1][1];
  ch[1][1][0].h5 = c5[1][1];
  copy(1, 1);
  for (int j = 2; j <= n; ++j) {
    ch[1][j][0].h2 = ch[1][j - 1][0].h2 + c2[1][j];
    ch[1][j][0].h5 = ch[1][j - 1][0].h5 + c5[1][j];
    ch[1][j][0].s = ch[1][j - 1][0].s + "R";
    copy(1, j);
  }
  for (int i = 2; i <= n; ++i) {
    ch[i & 1][1][0].h2 = ch[(i - 1) & 1][1][0].h2 + c2[i][1];
    ch[i & 1][1][0].h5 = ch[(i - 1) & 1][1][0].h5 + c5[i][1];
    ch[i & 1][1][0].s = ch[(i - 1) & 1][1][0].s + "D";
    copy(i, 1);
    for (int j = 2; j <= n; ++j) {
      int tmp[4][2];
      string tt[4];
      tmp[0][0] = ch[(i - 1) & 1][j][0].h2 + c2[i][j];
      tmp[0][1] = ch[(i - 1) & 1][j][0].h5 + c5[i][j];
      tt[0] = ch[(i - 1) & 1][j][0].s + "D";
      tmp[1][0] = ch[(i - 1) & 1][j][1].h2 + c2[i][j];
      tmp[1][1] = ch[(i - 1) & 1][j][1].h5 + c5[i][j];
      tt[1] = ch[(i - 1) & 1][j][1].s + "D";
      tmp[2][0] = ch[i & 1][j - 1][0].h2 + c2[i][j];
      tmp[2][1] = ch[i & 1][j - 1][0].h5 + c5[i][j];
      tt[2] = ch[i & 1][j - 1][0].s + "R";
      tmp[3][0] = ch[i & 1][j - 1][1].h2 + c2[i][j];
      tmp[3][1] = ch[i & 1][j - 1][1].h5 + c5[i][j];
      tt[3] = ch[i & 1][j - 1][1].s + "R";
      int h2c = 0, h5c = 0;
      for (int k = 1; k < 4; ++k) {
        if (tmp[k][0] < tmp[h2c][0] ||
            (tmp[k][0] == tmp[h2c][0] && tmp[k][1] < tmp[h2c][1]))
          h2c = k;
        if (tmp[k][1] < tmp[h5c][1] ||
            (tmp[k][1] == tmp[h5c][1] && tmp[k][0] < tmp[h5c][0]))
          h5c = k;
      }
      ch[i & 1][j][0].h2 = tmp[h2c][0];
      ch[i & 1][j][0].h5 = tmp[h2c][1];
      ch[i & 1][j][0].s = tt[h2c];
      ch[i & 1][j][1].h2 = tmp[h5c][0];
      ch[i & 1][j][1].h5 = tmp[h5c][1];
      ch[i & 1][j][1].s = tt[h5c];
    }
  }
  int a1 = min(ch[n & 1][n][0].h2, ch[n & 1][n][0].h5),
      a2 = min(ch[n & 1][n][1].h2, ch[n & 1][n][1].h5);
  if (spx && min(a1, a2) > 1) {
    puts("1");
    for (int i = 2; i <= spx; ++i) printf("R");
    for (int i = 2; i <= n; ++i) printf("D");
    for (int i = spx + 1; i <= n; ++i) printf("R");
    puts("");
  } else if (a1 < a2) {
    printf("%d\n", a1);
    cout << ch[n & 1][n][0].s;
    puts("");
  } else {
    printf("%d\n", a2);
    cout << ch[n & 1][n][1].s;
    puts("");
  }
}
