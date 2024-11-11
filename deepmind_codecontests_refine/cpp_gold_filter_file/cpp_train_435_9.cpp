#include <bits/stdc++.h>
using namespace std;
char s1[5005], s2[5005];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", s1, s2);
    if (strcmp(s1, s2) < 0) {
      printf("%s\n", s1);
      continue;
    }
    int len = strlen(s1);
    for (int i = 1; i < len; i++) {
      for (int j = 0; j < i; j++) {
        if (s1[j] > s1[i]) {
          swap(s1[j], s1[i]);
          if (strcmp(s1, s2) < 0) {
            printf("%s\n", s1);
            goto qwe;
          }
          swap(s1[j], s1[i]);
        }
      }
    }
    printf("---\n");
  qwe:;
  }
}
