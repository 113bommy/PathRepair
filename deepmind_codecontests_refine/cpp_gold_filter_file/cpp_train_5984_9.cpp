#include <bits/stdc++.h>
int main() {
  long long s[26], d[10];
  char ss[100001];
  for (int i = 0; i < 26; i++) {
    s[i] = 0;
  }
  for (int i = 0; i < 10; i++) {
    d[i] = 0;
  }
  scanf("%s", ss);
  int j = 0;
  while (ss[j] != '\0') {
    if (ss[j] >= 'a' && ss[j] <= 'z')
      s[ss[j] - 'a']++;
    else
      d[ss[j] - '0']++;
    j++;
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) ans += s[i] * s[i];
  for (int i = 0; i < 10; i++) ans += d[i] * d[i];
  printf("%I64d\n", ans);
  return 0;
}
