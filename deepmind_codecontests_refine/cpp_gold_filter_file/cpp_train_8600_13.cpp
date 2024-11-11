#include <bits/stdc++.h>
using namespace std;
int foo[30];
int comp[] = {4,  6,  8,  9,  10, 12, 14, 15, 16, 18,
              20, 21, 22, 24, 25, 26, 27, 28, 30, 32};
int main() {
  foo[0] = 0;
  for (int i = 1; i < 30; ++i) {
    int mx = -1;
    for (int j = 0; comp[j] <= i; j++) {
      if (foo[i - comp[j]] != -1) mx = max(mx, foo[i - comp[j]] + 1);
    }
    foo[i] = mx;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int a;
    scanf("%d", &a);
    if (a < 30) {
      cout << foo[a] << "\n";
      continue;
    }
    int res = -1;
    for (int i = 12; i <= 15; ++i) {
      int b = a - i;
      if (b % 4 == 0) res = max(res, foo[i] + b / 4);
    }
    printf("%d\n", res);
  }
}
