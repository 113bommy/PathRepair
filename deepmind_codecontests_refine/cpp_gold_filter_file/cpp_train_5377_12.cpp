#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (~scanf("%d", &n)) {
    int sum = 0;
    m = 1;
    while (n--) {
      if (n % m == 0) sum++;
      if (n <= m) break;
      m++;
    }
    printf("%d\n", sum);
  }
}
