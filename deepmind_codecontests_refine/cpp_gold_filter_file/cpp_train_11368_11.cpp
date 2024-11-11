#include <bits/stdc++.h>
using namespace std;
int len;
int jj[1050];
char str[1050];
int rec[26];
bool judge(int x) {
  if (x == 2) return true;
  if (x == 1) return false;
  if (jj[x] == 1) return true;
  if (jj[x] == 0 && 2 * x <= len) return true;
  return false;
}
int main() {
  memset(jj, 0, sizeof(jj));
  for (int i = 2; i <= 1000; i++) {
    if (!jj[i]) {
      for (int j = i + i; j <= 1000; j += i) jj[j] = 1;
    }
  }
  while (~scanf("%s", str)) {
    memset(rec, 0, sizeof(rec));
    len = strlen(str);
    for (int i = 0; i < len; i++) {
      rec[str[i] - 'a']++;
    }
    int M = 0, Mnum = rec[0];
    for (int i = 1; i < 26; i++) {
      if (Mnum < rec[i]) {
        Mnum = rec[i];
        M = i;
      }
    }
    char haha = M + 'a';
    int ok = 1;
    for (int i = 0; i < len; i++) {
      if (!judge(i + 1))
        continue;
      else {
        if (str[i] == haha)
          continue;
        else {
          ok = 0;
          for (int j = 0; j < len; j++) {
            if (!judge(j + 1) && str[j] == haha) {
              ok = 1;
              char tmp = str[i];
              str[i] = str[j];
              str[j] = tmp;
              break;
            }
          }
          if (ok == 0) break;
        }
      }
    }
    if (ok == 0)
      printf("NO\n");
    else {
      printf("YES\n");
      printf("%s\n", str);
    }
  }
  return 0;
}
