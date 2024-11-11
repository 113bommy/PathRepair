#include <bits/stdc++.h>
int cut[30], clt[30], cus[30], cls[30], a[200009];
int main() {
  char s[200009], t[200009];
  scanf("%s", s);
  scanf("%s", t);
  int l = strlen(s), m = strlen(t);
  int i;
  for (i = 0; i < l; i++) {
    if (s[i] >= 'a' && s[i] <= 'z')
      cls[s[i] - 'a']++;
    else
      cus[s[i] - 'A']++;
  }
  for (i = 0; i < m; i++) {
    if (t[i] >= 'a' && t[i] <= 'z')
      clt[t[i] - 'a']++;
    else
      cut[t[i] - 'A']++;
  }
  int yay = 0, whoops = 0;
  for (i = 0; i < l; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      if (clt[s[i] - 'a'] > 0) {
        yay++;
        clt[s[i] - 'a']--;
        a[i] = 1;
      }
    } else {
      if (cut[s[i] - 'A'] > 0) {
        yay++;
        cut[s[i] - 'A']--;
        a[i] = 1;
      }
    }
  }
  for (i = 0; i < l; i++) {
    if (!a[i]) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        if (cut[s[i] - 'a'] > 0) {
          whoops++;
          cut[s[i] - 'a']--;
          a[i] = 1;
        }
      } else {
        if (clt[s[i] - 'A'] > 0) {
          whoops++;
          cut[s[i] - 'A']--;
          a[i] = 1;
        }
      }
    }
  }
  printf("%d %d", yay, whoops);
  return 0;
}
