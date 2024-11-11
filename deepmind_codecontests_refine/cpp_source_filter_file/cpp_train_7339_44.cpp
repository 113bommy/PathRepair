#include <bits/stdc++.h>
using namespace std;
int n;
char S[10][10];
int Ans1 = 10, Ans2 = 10;
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
  for (int i = 1; i <= 8; i++) {
    scanf("%s", S[i]);
  }
  for (int i = 1; i <= 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (S[i][j] == 'W') {
        bool pd = true;
        for (int k = i - 1; k >= 1; k--) {
          if (S[k][j] == 'W' || S[k][j] == 'B') pd = false;
        }
        if (pd) Ans1 = min(Ans1, i - 1);
      }
      if (S[i][j] == 'B') {
        bool pd = true;
        for (int k = i + 1; k <= n; k++) {
          if (S[k][j] == 'W' || S[k][j] == 'B') pd = false;
        }
        if (pd) Ans2 = min(Ans2, 8 - i);
      }
    }
  }
  if (Ans1 <= Ans2)
    cout << "A" << endl;
  else
    cout << "B" << endl;
  return 0;
}
