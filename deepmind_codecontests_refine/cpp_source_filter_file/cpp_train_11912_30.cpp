#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
char s[maxn];
int ans[8] = {1869, 1896, 1986, 8691, 6198, 1689, 1968};
int main() {
  while (scanf("%s", s) != EOF) {
    int len = strlen(s);
    int A[10] = {0};
    for (int i = 0; i < len; i++) {
      A[s[i] - '0']++;
    }
    long long m = 0;
    for (int i = 1; i < A[1]; i++) {
      printf("1");
      m = (m * 10 + 1) % 7;
    }
    for (int i = 1; i <= A[2]; i++) {
      printf("2");
      m = (m * 10 + 2) % 7;
    }
    for (int i = 1; i <= A[3]; i++) {
      printf("3");
      m = (m * 10 + 3) % 7;
    }
    for (int i = 1; i <= A[4]; i++) {
      printf("4");
      m = (m * 10 + 4) % 7;
    }
    for (int i = 1; i <= A[5]; i++) {
      printf("5");
      m = (m * 10 + 5) % 7;
    }
    for (int i = 1; i < A[6]; i++) {
      printf("6");
      m = (m * 10 + 6) % 7;
    }
    for (int i = 1; i <= A[7]; i++) {
      printf("7");
      m = (m * 10 + 7) % 7;
    }
    for (int i = 1; i < A[8]; i++) {
      printf("8");
      m = (m * 10 + 8) % 7;
    }
    for (int i = 1; i < A[9]; i++) {
      printf("9");
      m = (m * 10 + 9) % 7;
    }
    m = (m * 1000) % 7;
    printf("%d", ans[m]);
    for (int i = 1; i <= A[0]; i++) printf("0");
    printf("\n");
  }
  return 0;
}
