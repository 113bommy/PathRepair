#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 110;
char m[MAXN][MAXN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 5) {
    printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
    return 0;
  } else if (n == 3) {
    printf(">vv\n^<.\n^.<\n1 3\n");
    return 0;
  }
  for (int a = 0; a < 100; ++a) {
    if (a % 2 == 0) {
      for (int b = 0; b < 33; ++b) printf(">");
      for (int b = 33; b < 99; ++b) printf("%c", b % 2 == 0 ? '.' : '>');
      printf("v\n");
    } else {
      printf("%c", a == 99 ? '^' : '.');
      for (int b = 1; b < 66; ++b) printf("%c", b % 2 == 0 ? '.' : '<');
      for (int b = 66; b < 100; ++b) printf("<");
      printf("\n");
    }
  }
  printf("99 1\n");
  return 0;
}
