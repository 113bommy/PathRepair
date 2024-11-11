#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  while (cin >> n) {
    if (n > 36) {
      printf("-1\n");
      continue;
    }
    if (n % 2 == 0) {
      for (i = 0; i < n / 2; i++) printf("8");
      printf("\n");
    } else {
      for (i = 0; i < n / 2; i++) printf("8");
      printf("6\n");
    }
  }
  return 0;
}
