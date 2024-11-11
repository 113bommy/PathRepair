#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int f[1000000][26], g[1000000][26], P, i, j;
char s1[1000000], s2[1000000];
long long ans, N, M, l;
int main() {
  scanf("%I64d%I64d%s%s", &N, &M, &s1, &s2);
  P = gcd(strlen(s1), strlen(s2));
  for (; s1[i]; ++i) f[i % P][s1[i] - 'a']++;
  for (; s2[j]; ++j) g[j % P][s2[j] - 'a']++;
  ans = (long long)i * j / P;
  l = (long long)N * P / j;
  for (i = 0; i <= P - 1; ++i)
    for (j = 0; j < 26; ++j) ans -= (long long)f[i][j] * g[i][j];
  ans *= l;
  printf("%I64d\n", ans);
}
