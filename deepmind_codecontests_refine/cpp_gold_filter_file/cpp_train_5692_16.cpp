#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
  char s[10];
  int a[10];
  scanf("%s", s);
  memset(a, 0, sizeof(a));
  for (int i = 0; i < 6; i++) {
    if (s[i] == 'R')
      a[0]++;
    else if (s[i] == 'O')
      a[1]++;
    else if (s[i] == 'Y')
      a[2]++;
    else if (s[i] == 'G')
      a[3]++;
    else if (s[i] == 'B')
      a[4]++;
    else if (s[i] == 'V')
      a[5]++;
  }
  sort(a, a + 6, cmp);
  if (a[0] == 6) {
    printf("1\n");
  } else if (a[0] == 5) {
    printf("1\n");
  } else if (a[0] == 4 && a[1] == 2) {
    printf("2\n");
  } else if (a[0] == 4) {
    printf("2\n");
  } else if (a[0] == 3 && a[1] == 3) {
    printf("2\n");
  } else if (a[0] == 3 && a[1] == 2) {
    printf("3\n");
  } else if (a[0] == 3) {
    printf("5\n");
  } else if (a[0] == 2 && a[1] == 2 && a[2] == 2) {
    printf("6\n");
  } else if (a[0] == 2 && a[1] == 2) {
    printf("8\n");
  } else if (a[0] == 2) {
    printf("15\n");
  } else {
    printf("30\n");
  }
  return 0;
}
