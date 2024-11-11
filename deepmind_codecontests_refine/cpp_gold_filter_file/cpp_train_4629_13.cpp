#include <bits/stdc++.h>
using namespace std;
int n;
void print5() {
  printf("YES\n");
  printf("5 - 1 = 4\n");
  printf("4 - 2 = 2\n");
  printf("2 * 3 = 6\n");
  printf("6 * 4 = 24\n");
}
void print6() {
  printf("YES\n");
  printf("1 * 2 = 2\n");
  printf("2 * 3 = 6\n");
  printf("6 * 4 = 24\n");
  printf("6 - 5 = 1\n");
  printf("24 * 1 = 24\n");
}
void print7() {
  printf("YES\n");
  printf("6 - 5 = 1\n");
  printf("7 - 1 = 6\n");
  printf("6 - 3 = 3\n");
  printf("2 * 3 = 6\n");
  printf("6 * 4 = 24\n");
  printf("1 * 24 = 24\n");
}
int main() {
  scanf("%d", &n);
  if (n < 4) {
    printf("NO\n");
    return 0;
  }
  if (n == 5) {
    print5();
    return 0;
  }
  if (n == 6) {
    print6();
    return 0;
  }
  if (n == 7) {
    print7();
    return 0;
  }
  printf("YES\n");
  printf("1 * 2 = 2\n");
  printf("2 * 3 = 6\n");
  printf("6 * 4 = 24\n");
  int one = 0;
  for (int i = 5; i < n; i += 2) {
    printf("%d - %d = 1\n", i + 1, i);
    one++;
  }
  int zer = 0;
  for (int i = 1; i < (n - 4) / 2; i += 2) {
    printf("1 - 1 = 0\n");
    zer++;
    one -= 2;
  }
  if ((n - 4) % 2) printf("0 * %d = 0\n", n);
  if (one) printf("0 * 1 = 0\n");
  while (zer > 1) {
    printf("0 + 0 = 0\n");
    zer--;
  }
  if (zer > 0) printf("24 + 0 = 24\n");
  return 0;
}
