#include <bits/stdc++.h>
using namespace std;
char check(char &lt, char &rt, char &lb, char &rb, short &c) {
  char x = ((lt == 15) * 8 + (rt == 15) * 4 + (lb == 15) * 2 + (rb == 15));
  if ((c < 0) || (((x == lt) || (lt == 15)) && ((x == rt) || (rt == 15)) &&
                  ((x == lb) || (lb == 15)) && ((x == rb) || (lb == 15))))
    return x;
  else
    return 16;
}
void rec(char *a, short n, short m, short x, unsigned long long &ans) {
  if (!n || !m) return;
  if (x > 0) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[(i * m) + j] != 16) ans++;
  }
  for (int I = 0; I < 2; I++)
    for (int J = 0; J < 2; J++) {
      char b[(n - I) / 2][(m - J) / 2];
      for (int i = 1 + I; i < n; i += 2)
        for (int j = 1 + J; j < m; j += 2)
          b[(i - I) / 2][(j - J) / 2] =
              check(a[(i - 1) * m + j - 1], a[(i - 1) * m + j],
                    a[i * m + j - 1], a[i * m + j], x);
      rec(&b[0][0], (n - I) / 2, (m - J) / 2, x + 1, ans);
    }
  return;
}
int main() {
  short n, m;
  unsigned long long ans = 0;
  cin >> n >> m;
  char a[n][m];
  for (short i = 0; i < n; i++)
    for (short j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = (c == '*' ? 15 : 0);
    }
  rec(&a[0][0], n, m, -1, ans);
  cout << ans;
  return 0;
}
