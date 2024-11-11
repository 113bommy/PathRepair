#include <bits/stdc++.h>
using namespace std;
char s1[50], s2[50], s3[5000], kt;
int main() {
  int i, j, len, hoa;
  while (scanf("%s %s %s", &s1, &s2, &s3) > 0) {
    len = strlen(s3);
    for (i = 0; i < len; i++) {
      hoa = 0;
      kt = s3[i];
      if (s3[i] < 'a') {
        hoa = 1;
        kt += 32;
      }
      for (j = 0; j < 26; j++) {
        if (kt == s1[j]) {
          s3[i] = s2[j];
          if (hoa == 1) {
            s3[i] -= 32;
          }
          break;
        }
      }
    }
    printf("%s\n", s3);
  }
  return 0;
}
