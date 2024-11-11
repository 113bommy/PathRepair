#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 5) {
    printf("2 4 1\n");
    printf("3 4 4\n");
    printf("1 3 2\n");
    printf("1 5 1\n");
    printf("1 2\n");
    printf("4 5\n");
    return 0;
  }
  int m = n / 2;
  for (int i = 1; i <= m; i++) printf("%d %d %d\n", i, i + m, 1);
  int t = 1;
  for (int i = m + 1; i < m * 2; i++) {
    printf("%d %d %d\n", i, i + 1, t);
    t += 2;
  }
  if (n % 2 == 1) printf("%d %d %d\n", n - 1, n, 1);
  for (int i = 1; i < m; i++) printf("%d %d\n", i, i + 1);
  printf("1 3\n");
  int x;
  cin >> x;
}
