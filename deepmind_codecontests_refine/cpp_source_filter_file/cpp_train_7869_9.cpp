#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, m, q;
int a[1110][810];
char s[1100];
int ni[5] = {0, 1, 3, 2, 4};
long long pow_mod(long long a, long long e) {
  long long res = 1;
  for (; e; a = a * a % mod, e >>= 1)
    if (e & 1) res = res * a % mod;
  return res;
}
int frnum;
const int BASE = 5;
int wr[1100];
void gauss() {
  for (int i = 1; i <= n; i++) {
    int flag = 0;
    for (int j = 1; j <= m; j++)
      if (a[j][i]) {
        for (int k = 1; k <= n + q; k++) swap(a[j][k], a[i][k]);
        flag = 1;
        break;
      }
    if (flag == 0) {
      m++;
      for (int j = 1; j <= n + q; j++) a[m][j] = a[i][j], a[i][j] = 0;
      continue;
    }
    for (int j = i + 1; j <= n + q; j++)
      a[i][j] = (a[i][j] * ni[a[i][i]]) % BASE;
    a[i][i] = 1;
    for (int j = 1; j <= m; j++)
      if (a[j][i] && j != i) {
        for (int k = 1; k <= n + q; k++)
          if (k != i)
            a[j][k] = (a[j][k] + 5 - (a[j][i] * a[i][k]) % BASE) % BASE;
        a[j][i] = 0;
      }
  }
  for (int i = 1; i <= n; i++)
    if (a[i][i] == 0) frnum++;
  for (int i = 1; i <= m; i++) {
    int ff = 0;
    for (int j = 1; j <= n; j++)
      if (a[i][j]) ff = 1;
    if (ff) continue;
    for (int j = n + 1; j <= n + q; j++)
      if (a[i][j]) wr[j - n] = 1;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++) a[j][i] = s[j] - 'a';
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++) a[j][i + n] = s[j] - 'a';
  }
  gauss();
  for (int i = 1; i <= q; i++) {
    if (wr[i])
      cout << 0 << endl;
    else
      cout << pow_mod(5, frnum) << endl;
  }
  return 0;
}
