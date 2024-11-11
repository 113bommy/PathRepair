#include <bits/stdc++.h>
using namespace std;
char s[2021];
bool tog1, tog2;
int t1, t2;
int main() {
  cin >> s;
  t2 = strlen(s);
  for (int i = 0; s[i]; i++) {
    if (i && s[i] == s[i - 1] && s[i] == '.') {
      puts("NO");
      return 0;
    }
    if (i && s[i] == s[i - 1] && s[i] == '/') {
      puts("NO");
      return 0;
    }
    if (s[i] == '@') {
      if (!tog1 && i)
        tog1 = true, t1 = i;
      else {
        puts("NO");
        return 0;
      }
    }
    if (s[i] == '/') {
      if (!tog2 && i && tog1)
        tog2 = true, t2 = i;
      else {
        puts("NO");
        return 0;
      }
    }
  }
  if (!tog1) {
    puts("NO");
    return 0;
  }
  if (t1 > 16) {
    puts("NO");
    return 0;
  }
  for (int i = 0; i < t1; i++) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
        (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
      continue;
    else {
      puts("NO");
      return 0;
    }
  }
  if (t2 - t1 <= 1) {
    puts("NO");
    return 0;
  }
  if (t2 - t1 - 1 > 32 || t2 - t1 - 1 < 0) {
    puts("NO");
    return 0;
  }
  int len1 = 0;
  for (int i = t1 + 1; i < t2; i++) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
        (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
      len1++;
    else if (s[i] == '.') {
      if (len1 <= 0 || len1 > 16 || i == t2 - 1) {
        puts("NO");
        return 0;
      } else
        len1 = 0;
    } else {
      puts("NO");
      return 0;
    }
    if (len1 > 16) {
      puts("NO");
      return 0;
    }
  }
  int len2 = 0;
  if (tog2) {
    if (!s[t2 + 1]) {
      puts("NO");
      return 0;
    }
    for (int i = t2 + 1; s[i]; i++)
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
          (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
        len2++;
      else {
        puts("NO");
        return 0;
      }
    if (len2 < 0 || len2 > 16) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}
