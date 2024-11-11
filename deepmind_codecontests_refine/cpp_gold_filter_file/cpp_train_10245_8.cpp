#include <bits/stdc++.h>
using namespace std;
int x[110], y[110];
char s[110];
int main() {
  int a, b, i;
  scanf("%d%d%s", &a, &b, s + 1);
  if (!a && !b) {
    cout << "Yes" << endl;
    return 0;
  }
  int N = strlen(s + 1);
  for (i = 1; i <= N; i++) {
    int dx = 0, dy = 0;
    if (s[i] == 'L') dx = -1;
    if (s[i] == 'R') dx = 1;
    if (s[i] == 'U') dy = 1;
    if (s[i] == 'D') dy = -1;
    x[i] = x[i - 1] + dx;
    y[i] = y[i - 1] + dy;
  }
  for (i = 1; i <= N; i++) {
    if (!((x[N] && (a - x[i]) % x[N] == 0 || !x[N] && a == x[i]) &&
          (y[N] && (b - y[i]) % y[N] == 0 || !y[N] && b == y[i])))
      continue;
    int p, q;
    if (x[N]) p = (a - x[i]) / x[N];
    if (y[N]) q = (b - y[i]) / y[N];
    if (!x[N] && q > 0 || !y[N] && p > 0 || x[N] && y[N] && p >= 0 && p == q) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
