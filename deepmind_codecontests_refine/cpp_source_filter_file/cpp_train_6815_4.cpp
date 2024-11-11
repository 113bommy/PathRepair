#include <bits/stdc++.h>
using namespace std;
char buf[1000010];
int preMOD[1000010][2], sufMOD[1000010][2];
int tenpow[1000010][2];
int main() {
  scanf("%s", buf + 1);
  int a, b;
  scanf("%d %d", &a, &b);
  tenpow[0][0] = 1 % a, tenpow[0][1] = 1 % b;
  int i = 1, j = 1;
  for (i = 1; i < 1000010; i++)
    tenpow[i][0] = (tenpow[i - 1][0] * 10) % a,
    tenpow[i][1] = (tenpow[i - 1][1] * 10) % b;
  int len = strlen(buf + 1);
  for (i = 1; i <= len; i++) {
    preMOD[i][0] = (preMOD[i - 1][0] * 10 % a + (buf[i] - '0')) % a;
    preMOD[i][1] = (preMOD[i - 1][1] * 10 % b + (buf[i] - '0')) % b;
  }
  for (i = len; i >= 1; i--) {
    sufMOD[i][0] =
        (tenpow[len - i][0] * (buf[i] - '0') % a + sufMOD[i + 1][0]) % a;
    sufMOD[i][1] =
        (tenpow[len - i][1] * (buf[i] - '0') % b + sufMOD[i + 1][1]) % b;
  }
  for (i = 1; i < len; i++) {
    if (preMOD[i][0] == 0 && sufMOD[i + 1][1] == 0 && buf[i + 1] != '0') {
      printf("YES\n");
      for (j = 1; j <= i; j++) printf("%c", buf[j]);
      printf("\n");
      for (j = 1; j <= len; j++) printf("%c", buf[j]);
      printf("\n");
      return 0;
    }
  }
  printf("NO");
  return 0;
}
