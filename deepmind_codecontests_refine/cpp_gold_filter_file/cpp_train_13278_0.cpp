#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool flag1 = false, flag2 = false;
  int i = 0;
  if (n == 1) return 0 & printf("I hate it");
  while (i < n) {
    for (int j = 0; j < 2; j++) {
      if (j == 0) {
        printf("I hate that ");
        i++;
        if (i == n - 1) {
          flag1 = true;
          break;
        }
      }
      if (j == 1) {
        printf("I love that ");
        i++;
        if (i == n - 1) {
          flag2 = true;
          break;
        }
      }
    }
    if (flag1 || flag2) break;
  }
  if (flag1) return 0 & printf("I love it");
  if (flag2) return 0 & printf("I hate it");
}
