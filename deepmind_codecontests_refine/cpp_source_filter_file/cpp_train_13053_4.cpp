#include <bits/stdc++.h>
using namespace std;
int n, pld[100003], z[300002], sPLD[100003], ans, sv1 = 0, sv2 = -1, sv3 = -1,
                                                  sv4, sv5;
char s[100003], s2[300002];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1, r = 0; i <= n; i++) {
    if (pld[r] + r >= i) pld[i] = min(pld[r] + r - i, pld[2 * r - i]);
    while (i - pld[i] > 1 && s[i + pld[i] + 1] == s[i - pld[i] - 1]) pld[i]++;
    if (pld[r] + r < pld[i] + i) r = i;
  }
  for (int i = 1; i <= n; i++)
    sPLD[i - pld[i]] = max(sPLD[i - pld[i]], pld[i] * 2 + 1);
  for (int i = 1; i <= n; i++) sPLD[i] = max(sPLD[i], sPLD[i - 1] - 2);
  for (int i = 1; i <= n; i++) s2[i] = s[n - i + 1];
  s2[n + 1] = '$';
  for (int i = 1; i <= n; i++) s2[i + n + 1] = s[i];
  for (int i = 2; i <= 2 * n + 1; i++) {
    z[i] = z[i - 1];
    while (z[i] != 0 && s2[z[i] + 1] != s2[i]) z[i] = z[z[i]];
    if (s2[z[i] + 1] == s2[i]) z[i]++;
  }
  for (int i = 1; i <= n; i++) z[i] = z[n + 1 + i];
  for (int i = 1; i <= n; i++) {
    if (sv1 < z[i - 1]) sv1 = z[i - 1], sv2 = i - 1;
    if (sPLD[i] + min(sv1, n - (i + sPLD[i] - 1)) > ans) {
      ans = sPLD[i] + min(sv1, n - (i + sPLD[i] - 1));
      sv3 = min(sv1, n - (i + sPLD[i] - 1));
      sv4 = sv2;
      sv5 = i;
    }
  }
  if (sv4 == -1)
    printf("1\n%d %d\n", sv5, sPLD[sv5]);
  else
    printf("3\n%d %d\n%d %d\n%d %d\n", sv4 - sv3 + 1, sv3, sv5, sPLD[sv5],
           n - sv3 + 1, sv3);
  return 0;
}
