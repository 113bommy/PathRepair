#include <bits/stdc++.h>
int main() {
  int s[52], t[52], h = 0, o = 0;
  for (int i = 0; i < 52; i++) {
    s[i] = 0;
    t[i] = 0;
  }
  char c;
  while (1) {
    scanf("%c", &c);
    if (c > 64)
      s[(c > 95) ? c - 71 : c - 65]++;
    else
      break;
  }
  while (1) {
    scanf("%c", &c);
    if (c > 64)
      t[(c > 95) ? c - 71 : c - 65]++;
    else
      break;
  }
  for (int i = 0; i < 52; i++) {
    if (s[i] > t[i]) {
      h += t[i];
      s[i] -= t[i];
      t[i] = 0;
    } else if (s[i]) {
      h += s[i];
      t[i] -= s[i];
      s[i] = 0;
    }
  }
  for (int i = 0; i < 26; i++) {
    s[i] += s[i + 26];
    t[i] += t[i + 26];
  }
  for (int i = 0; i < 26; i++) {
    if (s[i] > t[i]) {
      o += t[i];
      s[i] -= t[i];
      t[i] = 0;
    } else if (s[i]) {
      o += t[i];
      t[i] -= s[i];
      s[i] = 0;
    }
  }
  printf("%d %d", h, o);
}
