#include <bits/stdc++.h>
long long n, m;
char s[2000005], t[2000005];
int num[2000005][27];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  int a = strlen(s + 1);
  int b = strlen(t + 1);
  long long tmp = gcd(a, b);
  long long time = (long long)a * (long long)b / tmp;
  time = n / (time / a);
  for (int i = 1; i <= a; ++i) num[i % (int)tmp][s[i] - 'a']++;
  long long ans = 0;
  long long tot = a / tmp;
  for (int i = 1; i <= b; ++i) ans += tot - num[i % (int)tmp][t[i] - 'a'];
  long long last = time * ans;
  printf("%d\n", last);
  return 0;
}
