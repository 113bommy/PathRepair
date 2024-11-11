#include <bits/stdc++.h>
using namespace std;
char s[21], t[21];
int a[21], de[21], bin[1 << 14], num[1 << 14], n;
long long ans = 1000000000000000000LL, f[1 << 14];
inline long long solve() {
  for (int S = 1; S < 1 << n; S++) {
    num[S] = num[S - (1 << bin[S & -S])] - de[bin[S & -S] + 1];
    f[S] = 1000000000000000000LL;
    if (num[S] < 0 || num[S] >= 16) continue;
    for (int i = 1; i <= n; i++)
      if (S & (1 << i - 1))
        f[S] = min(f[S], f[S ^ (1 << i - 1)] + num[S] * (1ll << (i - 1) * 4));
  }
  return f[(1 << n) - 1];
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 0; i <= n; i++) bin[1 << i] = i;
  for (int i = 1; i <= n; i++)
    if (s[i] >= '0' && s[i] <= '9')
      a[n - i + 1] = s[i] - '0';
    else
      a[n - i + 1] = s[i] - 'a' + 10;
  for (int S = 0; S < (1 << n - 1); S++) {
    int sum = 0, kill = 0;
    for (int i = 1; i <= n; i++) {
      de[i] = a[i];
      if (S & (1 << i - 1)) de[i] -= 16;
      if (i > 1 && (S & (1 << i - 2)) > 0) de[i]++;
      if (de[i] >= 16 || de[i] <= -16) kill = 1;
      sum += de[i];
    }
    if (kill == 0 && sum == 0) ans = min(ans, solve());
  }
  if (ans == 1000000000000000000LL)
    printf("NO\n");
  else {
    int n = 0;
    while (ans > 0) {
      t[++n] = ans & 15;
      ans = ans >> 4;
    }
    for (int i = ::n; i >= 1; i--)
      if (t[i] < 10)
        printf("%c", t[i] + '0');
      else
        printf("%c", t[i] - 10 + 'a');
  }
  return 0;
}
