#include <bits/stdc++.h>
int main() {
  int len1, len2;
  char s[1010], t[1010], vowel[] = {'a', 'i', 'e', 'u', 'o'};
  bool hidups, hidupt, valid = true;
  scanf("%s\n%s", s, t);
  len1 = strlen(s);
  len2 = strlen(t);
  if (len1 != len2)
    printf("No\n");
  else {
    for (int i = 0; i < len1; i++) {
      hidups = false;
      hidupt = false;
      for (int j = 0; j < 5; j++) {
        if (s[i] == vowel[j]) hidups = true;
        if (t[i] == vowel[j]) hidupt = true;
      }
      if (hidups != hidupt) {
        valid = false;
        break;
      }
    }
    if (valid)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
