#include <bits/stdc++.h>
using namespace std;
char s1[50], s2[50], s[1010];
int l;
int ss[50];
int main() {
  scanf("%s", &s1);
  scanf("%s", &s2);
  scanf("%s", &s);
  l = strlen(s);
  for (int i = 0; i < 26; i++) {
    int x = s1[i];
    int x1 = s2[i];
    ss[x] = x1;
  }
  for (int i = 0; i < l; i++) {
    if (s[i] <= 'z' && s[i] >= 'a') {
      int x = s[i];
      printf("%c", ss[x]);
      continue;
    }
    if (s[i] <= 'Z' && s[i] >= 'A') {
      int x = s[i] + 32;
      printf("%c", ss[x] - 32);
      continue;
    }
    printf("%c", s[i]);
  }
  return 0;
}
