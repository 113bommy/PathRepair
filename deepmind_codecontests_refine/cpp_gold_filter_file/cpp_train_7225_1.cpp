#include <bits/stdc++.h>
using namespace std;
char s1[1000005], s2[1000005];
long long num[1000005][26];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long n, m, la, lb;
  int i;
  scanf("%I64d%I64d", &n, &m);
  scanf("%s", s1);
  scanf("%s", s2);
  la = strlen(s1);
  lb = strlen(s2);
  long long t = gcd(la, lb);
  long long lcm = la / t * lb;
  long long tot = lcm;
  for (i = 0; i < la; i++) {
    num[i % t][s1[i] - 'a']++;
  }
  for (i = 0; i < lb; i++) {
    tot -= num[i % t][s2[i] - 'a'];
  }
  printf("%I64d\n", tot * (n / (lcm / la)));
  return 0;
}
