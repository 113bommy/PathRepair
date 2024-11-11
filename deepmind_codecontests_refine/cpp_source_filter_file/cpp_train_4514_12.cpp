#include <bits/stdc++.h>
using namespace std;
char s[128];
int n;
bool legal(int i, int a, int b) {
  int c = s[i], d = s[(i + 1) % n];
  if (a == 1 && c == 1) {
    if (d == 1)
      return true;
    else
      return b == 0;
  }
  if (a == 0 && c == 1) {
    if (d == 1)
      return false;
    else
      return b == 1;
  }
  if (a == 1 && c == 0) {
    if (d == 1)
      return true;
    else
      return b == 0;
  }
  if (a == 0 && c == 0) {
    if (d == 1)
      return b == 0;
    else
      return b == 1;
  }
  return false;
}
long long Solve(int first) {
  long long f[101][2];
  memset(f, 0, sizeof(f));
  f[0][first] = 1;
  for (int i = 0; i + 1 < n; i++) {
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        if (legal(i, a, b)) f[i + 1][b] += f[i][a];
      }
    }
  }
  return legal(n - 1, 0, first) * f[n - 1][0] +
         legal(n - 1, 1, first) * f[n - 1][1];
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) s[i] = 1 ^ (s[i] - 'A');
  long long ret = Solve(0) + Solve(1);
  cout << ret << endl;
  return 0;
}
