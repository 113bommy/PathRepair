#include <bits/stdc++.h>
using namespace std;
int h[4][4];
int df[4][4];
bool ans = true;
int f[4];
int diff322(int a, int b, int c, int d) { return h[a][b] - h[c][d]; }
int diff3(int a, int b, int c, int d) {
  int ret = h[a][c] + h[a][d] - h[b][c] - h[b][d];
  if (ret % 2 == 1) ans = false;
  return (ret) / 2;
}
char s[4][1000000];
int main() {
  memset(h, 0, sizeof h);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      cin >> h[i][j];
      h[j][i] = h[i][j];
    }
  }
  memset(f, 0, sizeof f);
  f[1] = diff3(1, 0, 2, 3);
  f[2] = diff3(2, 0, 1, 3);
  f[3] = diff3(3, 0, 1, 2);
  int cc = f[0];
  cc = min(cc, f[1]);
  cc = min(cc, f[2]);
  cc = min(cc, f[3]);
  for (int i = 0; i < 4; i++) f[i] -= cc;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (i != j) {
        h[i][j] -= f[i] + f[j];
        if (h[i][j] < 0) ans = false;
      }
  if (h[0][1] != h[2][3]) ans = false;
  if (h[1][2] != h[0][3]) ans = false;
  if (h[0][2] != h[1][3]) ans = false;
  memset(df, 0, sizeof df);
  if ((h[0][1] + h[1][2] + h[2][0]) % 2 == 1) ans = false;
  int ssum = h[0][1] + h[1][2] + h[2][0];
  df[1][0] = df[0][1] = ssum / 2 - h[0][1];
  df[2][0] = df[0][2] = ssum / 2 - h[0][2];
  df[2][1] = df[1][2] = ssum / 2 - h[1][2];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (df[i][j] < 0) ans = false;
  if (!ans)
    cout << -1;
  else {
    cout << df[1][0] + df[2][0] + df[1][2] + f[0] + f[1] + f[2] + f[3];
    int llen = 0;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < f[i]; j++) {
        for (int k = 0; k < 4; k++)
          if (i == k)
            s[k][llen] = 'a';
          else
            s[k][llen] = 'b';
        llen++;
      }
    for (int i = 0; i < df[1][0]; i++) {
      s[1][llen] = 'a';
      s[0][llen] = 'a';
      s[2][llen] = 'b';
      s[3][llen] = 'b';
      llen++;
    }
    for (int i = 0; i < df[2][0]; i++) {
      s[2][llen] = 'a';
      s[0][llen] = 'a';
      s[1][llen] = 'b';
      s[3][llen] = 'b';
      llen++;
    }
    for (int i = 0; i < df[1][2]; i++) {
      s[1][llen] = 'a';
      s[2][llen] = 'a';
      s[0][llen] = 'b';
      s[3][llen] = 'b';
      llen++;
    }
    s[0][llen] = '\0';
    s[1][llen] = '\0';
    s[2][llen] = '\0';
    s[3][llen] = '\0';
    cout << "\n" << s[0] << "\n" << s[1] << "\n" << s[2] << "\n" << s[3];
  }
}
