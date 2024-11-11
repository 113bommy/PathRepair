#include <bits/stdc++.h>
using namespace std;
char S1[10000];
char S2[10000];
long long D[5010][5010];
int main() {
  int a, b, i, j;
  scanf("%s\n%s", S1, S2);
  a = strlen(S1);
  b = strlen(S2);
  D[0][0] = (S1[0] == S2[0]);
  for (i = 1; i < a; ++i) D[i][0] = (S1[i] == S2[0]);
  for (j = 0; j < b; ++j) D[0][j] = D[0][j - 1] + (S1[0] == S2[j]);
  for (i = 1; i < a; ++i)
    for (j = 1; j < b; ++j) {
      D[i][j] = D[i][j - 1];
      if (S1[i] == S2[j]) D[i][j] += D[i - 1][j - 1] + 1;
      D[i][j] = (D[i][j] % 1000000007);
    }
  int ans = 0;
  for (i = 0; i < a; ++i) ans = (ans + D[i][b - 1]) % 1000000007;
  printf("%d\n", ans);
  return 0;
}
