#include <bits/stdc++.h>
using namespace std;
int main() {
  int testcount;
  assert(scanf("%d", &testcount) == 1);
  while (testcount--) {
    static char s[1000];
    assert(scanf("%s", s) == 1);
  }
  for (int i = 0; i <= 8; i++) {
    printf("%d?\?<>%d\n", i, i + 1);
  }
  printf("99?\?>>9?\?0\n");
  printf("9?\?<>10\n");
  for (int i = 0; i <= 9; i++) {
    printf("?%d?>>%d?\n", i, i);
  }
  for (int i = 0; i <= 9; i++) {
    printf("?%d>>%d?\n", i, i);
  }
  printf("?>>??\n");
  for (int i = 0; i <= 9; i++) {
    printf("%d>>%d?\n", i, i);
  }
  return 0;
}
