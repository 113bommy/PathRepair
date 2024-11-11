#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
char ans[2][1005];
bool x[5005];
int oprd[2][5005];
char orig[5005][1005];
char op[5005][20];
char input[4][1005];
char line[4 * 1005];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    mp.clear();
    for (int i = (1); i <= (n); i++) {
      fgets(line, 4 * 1005, stdin);
      int num = sscanf(line, "%s := %s %s %s", input[0], input[1], input[2],
                       input[3]);
      mp[string(input[0])] = i;
      if (num == 4) {
        if (input[1][0] == '?')
          oprd[0][i] = -1;
        else
          oprd[0][i] = mp[string(input[1])];
        strcpy(op[i], input[2]);
        if (input[3][0] == '?')
          oprd[1][i] = -1;
        else
          oprd[1][i] = mp[string(input[3])];
      } else
        op[i][0] = '#', strcpy(orig[i], input[2]);
    }
    for (int i = (0); i <= (m - 1); i++) {
      int val[2];
      val[0] = val[1] = 0;
      for (int j = (0); j <= (1); j++) {
        for (int k = (1); k <= (n); k++) {
          if (op[k][0] == '#')
            x[k] = orig[k][i] - '0';
          else {
            int oprd1 = (oprd[0][k] == -1 ? j : x[oprd[0][k]]);
            int oprd2 = (oprd[1][k] == -1 ? j : x[oprd[1][k]]);
            if (op[k][0] == 'X')
              x[k] = oprd1 ^ oprd2;
            else if (op[k][0] == 'O')
              x[k] = oprd1 | oprd2;
            else
              x[k] = oprd1 & oprd2;
          }
          val[j] += x[k];
        }
      }
      ans[0][i] = (val[0] <= val[1] ? '0' : '1');
      ans[1][i] = (val[0] < val[1] ? '1' : '0');
    }
    ans[0][m] = ans[1][m] = '\0';
    printf("%s\n", ans[0]);
    printf("%s\n", ans[1]);
  }
  return 0;
}
