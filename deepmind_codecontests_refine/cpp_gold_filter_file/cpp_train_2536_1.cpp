#include <bits/stdc++.h>
using namespace std;
int min(int x, int y) { return x < y ? x : y; }
int max(int x, int y) { return x > y ? x : y; }
const int N = 105;
const int M = 1100005;
char s[N];
int main() {
  int i, j, k = 1;
  int n, m, h, t;
  while (scanf("%s", s) != EOF) {
    m = strlen(s);
    if (s[0] == 'f')
      i = 4, printf("ftp://%c", s[3]);
    else
      i = 5, printf("http://%c", s[4]);
    int mark = 0;
    for (; i < m; i++) {
      if (s[i] == 'r' && s[i + 1] == 'u' && mark == 0) {
        mark = 1;
        printf(".ru");
        if (i + 2 != m) printf("/");
        i++;
      } else
        printf("%c", s[i]);
    }
    printf("\n");
  }
  return 0;
}
