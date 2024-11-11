#include <bits/stdc++.h>
using namespace std;
int A[1050];
int ans1, ans2;
int main() {
  int i, n;
  int flag = 1;
  int a;
  char b;
  while (scanf("%d", &a) != EOF) {
    A[a] = 1;
    if (scanf("%c", &b) == EOF) break;
  }
  for (i = 1; i <= 1001; i++) {
    if (A[i]) {
      if (ans1 == 0)
        ans1 = i;
      else
        ans2 = i;
    } else {
      if (ans1 && ans2) {
        if (flag) {
          printf("%d-%d", ans1, ans2);
          flag = 0;
        } else {
          printf(",%d-%d", ans1, ans2);
        }
        ans1 = ans2 = 0;
      } else if (ans1 && ans2 == 0) {
        if (flag) {
          printf("%d", ans1);
          flag = 0;
        } else {
          printf(",%d", ans1);
        }
        ans1 = 0;
      }
    }
  }
  return 0;
}
