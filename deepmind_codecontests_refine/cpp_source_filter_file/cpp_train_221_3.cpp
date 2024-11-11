#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const double pi = acos(-1.0);
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
char str[100100];
int nxt[100100][31], sum[300][300][300], n, q, len[4], head[50];
char s[4][250], op[4], st[100100], add[20];
int main() {
  n = read();
  q = read();
  scanf("%s", st + 1);
  for (register int i = 0; i <= 26; i++) head[i] = 1000000007;
  for (register int i = n; i >= 1; i--) {
    for (register int j = 0; j <= 26; j++) nxt[i][j] = head[j];
    head[st[i] - 'a'] = i;
  }
  while (q--) {
    scanf("%s", op + 1);
    int pos = read();
    if (op[1] == '+') {
      scanf("%s", add + 1);
      char ch = add[1];
      s[pos][++len[pos]] = add[1];
      int l = len[pos];
      if (pos == 1) {
        for (register int i = 0; i <= len[2]; i++) {
          for (register int j = 0; j <= len[3]; j++) {
            int &v = sum[len[pos]][i][j];
            v = 1000000007;
            if (sum[len[pos] - 1][i][j] <= n)
              v = nxt[sum[len[pos] - 1][i][j]][ch - 'a'];
            if (i != 0) {
              int tmppos = sum[len[pos]][i - 1][j];
              if (tmppos <= n) v = min(v, nxt[tmppos][s[2][i] - 'a']);
            }
            if (j != 0) {
              int tmppos = sum[len[pos]][i][j - 1];
              if (tmppos <= n) v = min(v, nxt[tmppos][s[3][j] - 'a']);
            }
          }
        }
      }
      if (pos == 2) {
        for (register int i = 0; i <= len[1]; i++) {
          for (register int j = 0; j <= len[3]; j++) {
            int &v = sum[i][l][j];
            v = 1000000007;
            if (sum[i][l - 1][j] <= n) v = nxt[sum[i][l - 1][j]][ch - 'a'];
            if (i) {
              int tmppos = sum[i - 1][len[pos]][j];
              if (tmppos <= n) v = min(v, nxt[tmppos][s[1][i] - 'a']);
            }
            if (j) {
              int tmppos = sum[i][l][j - 1];
              if (tmppos <= n) v = min(v, nxt[tmppos][s[3][j] - 'a']);
            }
          }
        }
      }
      if (pos == 3) {
        for (register int i = 0; i <= len[1]; i++) {
          for (register int j = 0; j <= len[2]; j++) {
            int &v = sum[i][j][l];
            v = 1000000007;
            if (sum[i][j][l - 1] <= n) v = nxt[sum[i][j][l - 1]][ch - 'a'];
            if (i) {
              int tmppos = sum[i - 1][j][l];
              if (tmppos <= n) v = min(v, nxt[tmppos][s[1][i] - 'a']);
            }
            if (j) {
              int tmppos = sum[i][j - 1][l];
              if (tmppos <= n) v = min(v, nxt[tmppos][s[2][j] - 'a']);
            }
          }
        }
      }
    } else {
      len[pos]--;
    }
    if (sum[len[1]][len[2]][len[3]] <= n)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
