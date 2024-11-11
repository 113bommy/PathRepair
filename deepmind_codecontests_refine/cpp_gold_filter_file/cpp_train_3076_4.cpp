#include <bits/stdc++.h>
int dp[505];
int dp2[505][505];
int res[505];
int main(void) {
  int n;
  int k;
  scanf("%i %i", &n, &k);
  dp[0] = 0;
  int i;
  int j;
  int l;
  for (i = 1; i <= k; i++) {
    dp[i] = 100000;
  }
  int Pole[n];
  for (i = 0; i < n; i++) {
    scanf("%i", &Pole[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = k; j >= 0; j--) {
      if (dp[j] < 1000 && j + Pole[i] <= k && dp[j + Pole[i]] > 1000) {
        dp[j + Pole[i]] = i + 1;
      }
    }
  }
  dp2[k][0] = 1;
  res[0] = 1;
  for (i = n - 1; i >= 0; i--) {
    for (j = 0; j <= k; j++) {
      for (l = k; l >= 0; l--) {
        if (dp2[j][l] == 1) {
          if (j - Pole[i] >= 0 && dp[j - Pole[i]] <= i) {
            dp2[j - Pole[i]][l + Pole[i]] = 1;
            dp2[j - Pole[i]][l] = 1;
            res[l + Pole[i]] = 1;
          }
          if (dp[j] == i + 1) dp2[j][l] = 0;
        }
      }
    }
  }
  int pocet = 0;
  for (i = 0; i <= k; i++) {
    if (res[i] == 1) pocet++;
  }
  printf("%i\n", pocet);
  for (i = 0; i <= k; i++) {
    if (res[i] == 1) printf("%i ", i);
  }
  printf("\n");
  return 0;
}
