#include <bits/stdc++.h>
using namespace std;
long long n, m;
char s1[1000010], s2[1000010];
int dpa[1000010][30], dpb[1000010][30];
int gcd(int x, int y) {
  if (x % y == 0) return y;
  return gcd(y, x % y);
}
int main() {
  int i, j, k, len1, len2;
  long long d, dis;
  while (scanf("%I64d %I64d", &n, &m) != EOF) {
    scanf("%s %s", s1, s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    int g = gcd(len1, len2);
    memset(dpa, 0, sizeof(dpa));
    memset(dpb, 0, sizeof(dpb));
    for (i = 0; i < len1; i++) dpa[i % g][s1[i] - 'a']++;
    for (i = 0; i < len2; i++) dpb[i % g][s2[i] - 'a']++;
    d = 0;
    for (i = 0; i < g; i++)
      for (j = 0; j < 26; j++) {
        d += (long long)dpa[i][j] * (long long)dpb[i][j];
      }
    dis = (long long)n * len1 - (long long)(d * g / len2 * n);
    printf("%I64d\n", dis);
  }
  return 0;
}
