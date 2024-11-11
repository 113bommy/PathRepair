#include <bits/stdc++.h>
long long mod = 1000000007;
long long mas[2001][2001];
int min(int a, int b) {
  int res = a;
  if (a > b) res = b;
  return res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  char s[m + 1];
  scanf("%s", s);
  mas[0][0] = 1;
  for (int i = 1; i < n - m + 1; i++) {
    mas[i][0] = mas[i - 1][1] % mod;
    for (int j = 1; j < i + 1; j++)
      mas[i][j] = (mas[i - 1][j + 1] + mas[i - 1][j - 1]) % mod;
  }
  int minim = INT_MAX;
  int xc = 0;
  for (int i = 0; i < m; i++) {
    if (s[i] == '(')
      xc++;
    else
      xc--;
    minim = min(minim, xc);
  }
  minim = minim * -1;
  long long res = 0;
  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (j >= minim) {
        if (j + xc <= n - m - i)
          res += ((mas[i][j] * mas[n - m - i][j + xc]) % mod);
        res %= mod;
      }
    }
  }
  std::cout << res;
  return 0;
}
