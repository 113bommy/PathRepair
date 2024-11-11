#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a * b < n) {
    printf("-1");
    return 0;
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      int c;
      if (!(i % 2))
        c = i * b + j + 1;
      else
        c = (i + 1) * b - j;
      if (c <= n)
        printf("%d ", c);
      else
        printf("0 ");
    }
    printf("\n");
  }
  return 0;
}
