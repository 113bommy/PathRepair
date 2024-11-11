#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, g, h, i, j, k;
char w[1000005];
int L[1000005], R[1000005];
int f[1000005][2][2];
int z[1000005], top;
char ch;
int l, r;
int k1, k2, k3, k4;
int an;
int main() {
  scanf("%d", &a);
  scanf("%s", w + 1);
  d = strlen(w + 1);
  for (i = 1; i <= d; i++) {
    ch = w[i];
    if (ch == '(') z[++top] = i;
    if (ch == ')') {
      L[i] = z[top];
      R[z[top]] = i;
      top--;
    }
    if (ch == '0') f[i][0][0] = 1;
    if (ch == '1') f[i][1][1] = 1;
    if (ch == '?') {
      f[i][0][1] = 1;
      f[i][1][0] = 1;
    }
  }
  for (i = 1; i <= d; i++)
    if (w[i] == ')') {
      if (w[i - 1] != ')') {
        ch = w[i - 2];
        l = i - 3;
        r = i - 1;
      } else {
        ch = L[w[i - 1]] - 1;
        l = L[w[i - 1]] - 2;
        r = i - 1;
      }
      for (k1 = 0; k1 <= 1; k1++)
        for (k2 = 0; k2 <= 1; k2++)
          if (f[l][k1][k2] == 1) {
            for (k3 = 0; k3 <= 1; k3++)
              for (k4 = 0; k4 <= 1; k4++)
                if (f[r][k3][k4] == 1) {
                  if (ch == '&') f[i][k1 & k3][k2 & k4] = 1;
                  if (ch == '|') f[i][k1 | k3][k2 | k4] = 1;
                  if (ch == '^') f[i][k1 ^ k3][k2 ^ k4] = 1;
                }
          }
    }
  an = f[d][0][1] | f[d][1][0];
  if (an == 1)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
