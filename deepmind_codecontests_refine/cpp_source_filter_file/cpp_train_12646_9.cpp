#include <bits/stdc++.h>
bool j = 1, t = 1;
bool alpha[26];
int main() {
  int n;
  scanf("%d", &n);
  char s[n];
  int i;
  scanf("%s", s);
  for (i = 0; i < n; i++) {
    s[i] = tolower(s[i]);
    alpha[s[i] - 'a'] = 1;
  }
  for (i = 0; i < 26; i++) {
    if (!s[i]) t = 0;
  }
  if (t) printf("YES");
  if (!t) printf("NO");
  return 0;
}
