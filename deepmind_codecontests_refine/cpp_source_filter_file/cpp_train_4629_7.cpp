#include <bits/stdc++.h>
using namespace std;
int ans4[3][3] = {4, 3, 12, 12, 2, 24, 24, 1, 24};
char op4[3] = {'*', '*', '*'};
int ans5[4][3] = {5, 4, 20, 20, 3, 23, 23, 2, 25, 25, 1, 24};
char op5[4] = {'*', '+', '+', '-'};
int ans7[6][3] = {6, 4, 24, 7, 5, 2, 2, 2, 4, 4, 3, 1, 1, 1, 0, 24, 0, 24};
char op7[6] = {'*', '-', '+', '-', '-', '+'};
char ans[10000000];
int sz = 0;
char buf[100];
void add(string s) {
  for (int i = 0; i < s.size(); i++) ans[sz++] = s[i];
  ans[sz++] = '\n';
}
int main() {
  int n;
  scanf("%d", &n);
  if (n < 4) {
    printf("NO\n");
    return 0;
  }
  int ost = n % 4;
  int cntz = 0;
  for (int i = n; i - 4 >= 4; i -= 4) {
    sprintf(buf, "%d - %d = %d", i, i - 1, 1), add(buf);
    sprintf(buf, "%d - %d = %d", i - 2, i - 3, 1), add(buf);
    add("1 - 1 = 0");
    cntz++;
  }
  if (ost == 2) {
    sprintf(buf, "6 - 5 = 1"), add(buf);
    add("1 - 1 = 0");
    cntz++;
  }
  for (int i = 1; i < cntz; i++) add("0 + 0 = 0");
  if (ost == 3) {
    for (int i = 0; i < 6; i++)
      sprintf(buf, "%d %c %d = %d", ans7[i][0], op7[i], ans7[i][1], ans7[i][2]),
          add(buf);
  } else if (ost == 1) {
    for (int i = 0; i < 4; i++)
      sprintf(buf, "%d %c %d = %d", ans5[i][0], op5[i], ans5[i][1], ans5[i][2]),
          add(buf);
  } else {
    for (int i = 0; i < (ost == 0 ? 3 : 2); i++)
      sprintf(buf, "%d %c %d = %d", ans4[i][0], op4[i], ans4[i][1], ans4[i][2]),
          add(buf);
  }
  if (cntz > 0) add("24 + 0 = 0");
  ans[sz++] = 0;
  printf("YES\n%s", ans);
  return 0;
}
