#include <bits/stdc++.h>
using namespace std;
const int maxn = 500500;
char s1[maxn], s2[32];
int main() {
  while (scanf("%s%s", s1, s2) != EOF) {
    int cnt = 0;
    for (int i = 0; s1[i]; i++) {
      if (s1[i] == s2[0]) {
        int tmp = 0;
        for (int j = 0; s2[j] && s1[i + j]; j++) {
          if (s2[j] == s1[i + j])
            tmp++;
          else
            break;
        }
        if (tmp == strlen(s2)) cnt++, i += tmp;
      }
    }
    printf("%d\n", cnt);
  }
}
