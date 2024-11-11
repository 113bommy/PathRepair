#include <bits/stdc++.h>
using namespace std;
int f[15][15];
char s[100010];
int main() {
  f[3][3] = 1;
  f[4][6] = f[6][4] = 1;
  f[7][7] = 1;
  f[5][9] = f[9][5] = 1;
  f[8][0] = f[0][8] = 1;
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  bool fl = true;
  for (int i(1); i <= (n / 2 + 1); ++i)
    if (!f[(int)s[i] - 48][(int)s[n - i + 1] - 48]) {
      fl = false;
      break;
    }
  puts(fl ? "Yes" : "No");
  return 0;
}
