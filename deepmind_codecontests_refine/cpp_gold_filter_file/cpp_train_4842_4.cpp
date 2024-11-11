#include <bits/stdc++.h>
using namespace std;
int n, Ans;
char S[1010];
int len[110], C[110][2];
bool flag[110];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read();
  memset(flag, 1, sizeof(flag));
  for (int i = 1; i <= n; i++) {
    scanf("%s", S);
    len[i] = strlen(S);
    for (int j = 0; j < len[i]; j++) {
      int x = S[j] - 'a' + 1;
      if (x != C[i][0] && x != C[i][1]) {
        if (C[i][0] == 0)
          C[i][0] = x;
        else if (C[i][1] == 0)
          C[i][1] = x;
        else
          flag[i] = false;
      }
    }
  }
  for (int i = 1; i <= 26; i++) {
    for (int j = 1; j <= 26; j++) {
      int sum = 0;
      for (int k = 1; k <= n; k++) {
        if (!flag[k]) continue;
        if ((C[k][0] == i || C[k][0] == j) &&
            (C[k][1] == i || C[k][1] == j || C[k][1] == 0))
          sum += len[k];
      }
      if (sum > Ans) Ans = sum;
    }
  }
  cout << Ans << endl;
  return 0;
}
