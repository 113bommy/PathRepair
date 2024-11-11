#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
string S;
int flag[N][40], flag1[40];
char A[N];
int main() {
  int i, len, j, begin, t, tt;
  char p;
  while (scanf("%s", A + 1) != EOF) {
    memset(flag1, -1, sizeof(flag1));
    memset(flag, 0, sizeof(flag));
    len = strlen(A + 1);
    for (i = 1; i <= len; i++) {
      flag1[A[i] - 'a' + 1] = i;
      flag[i][A[i] - 'a' + 1]++;
      for (j = 1; j < 27; j++) flag[i][j] += flag[i - 1][j];
    }
    begin = 1;
    tt = 1;
    S = 'a';
    for (i = 26; i > 0; i--) {
      if (flag1[i] >= 0 && flag1[i] >= tt) {
        t = flag[flag1[i]][i] - flag[tt - 1][i];
        p = i + 'a' - 1;
        S.insert(begin, t, p);
        begin += t;
        tt = flag1[i];
      }
    }
    for (i = 1; i < (int)S.length(); i++) printf("%c", S[i]);
    printf("\n");
  }
  return 0;
}
