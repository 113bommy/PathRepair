#include <bits/stdc++.h>
char s[1005];
int zi[26] = {}, sum[2] = {};
int main() {
  scanf("%s", s);
  for (int i = 0; s[i]; ++i) zi[s[i] - 'a']++;
  for (int i = 0; i < 26; ++i) sum[zi[i] % 2]++;
  if (sum[1] <= 1)
    printf("First\n");
  else
    printf(sum[1] % 2 ? "First\n" : "Second\n");
  return 0;
}
