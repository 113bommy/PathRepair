#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int k = 0;
  for (int i = 1; i <= n; ++i) {
    ++k;
    int temp = k;
    for (int j = 1; j <= n - 1; ++j) {
      printf("%d ", temp);
      temp += n + 1;
      if (temp == n * (j + 1) + 1) temp -= n;
    }
    printf("%d\n", temp);
  }
  return 0;
}
