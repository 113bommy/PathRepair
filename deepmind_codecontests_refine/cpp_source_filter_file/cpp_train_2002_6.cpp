#include <bits/stdc++.h>
using namespace std;
int n, m, K;
int tab[1005][1005], suma[1005][1005];
char s[1005][1005];
int main() {
  scanf("%d %d %d", &n, &m, &K);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < m - 2; j++)
      tab[i + 1][j + 1] = (s[i + 1][j] & s[i][j + 1] & s[i + 1][j + 1] &
                           s[i + 1][j + 2] & s[i + 2][j + 1]) -
                          '0';
  n--;
  m--;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      suma[i][j] =
          tab[i][j] + suma[i - 1][j] + suma[i][j - 1] - suma[i - 1][j - 1];
    }
  }
  int l = 0;
  long long wynik = 0;
  for (int p = 1; p < n; p++)
    for (int k = p; k < n; k++) {
      l = 1;
      for (int i = 1; i < m; i++) {
        while (l < m && (suma[k][l] - suma[p - 1][l] - suma[k][i - 1] +
                         suma[p - 1][i - 1]) < K)
          l++;
        if ((suma[k][l] - suma[p - 1][l] - suma[k][i - 1] +
             suma[p - 1][i - 1]) < K)
          break;
        wynik += m - i - 1;
      }
    }
  printf("%I64d\n", wynik);
  return 0;
}
