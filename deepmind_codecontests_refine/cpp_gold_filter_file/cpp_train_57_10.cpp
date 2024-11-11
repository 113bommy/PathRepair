#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
int n, m;
char s1[MAX], s2[MAX];
int main() {
  int i, j, k, t;
  while (~scanf("%s%s", s1, s2)) {
    scanf("%d", &n);
    printf("%s %s\n", s1, s2);
    while (n--) {
      char c1[MAX], c2[MAX];
      scanf("%s%s", c1, c2);
      if (strcmp(s1, c1) == 0)
        strcpy(s1, c2);
      else
        strcpy(s2, c2);
      printf("%s %s\n", s1, s2);
    }
  }
}
