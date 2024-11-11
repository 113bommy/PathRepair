#include <bits/stdc++.h>
int main() {
  char s[101];
  int cnt[2] = {};
  scanf("%s", s);
  for (int i = 0; s[i]; i++) cnt[s[i] == '-']++;
  printf("%s\n", cnt[0] == 0 || cnt[1] % cnt[0] ? "NO" : "YES");
}
