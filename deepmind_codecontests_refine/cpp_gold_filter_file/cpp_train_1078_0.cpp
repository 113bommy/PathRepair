#include <bits/stdc++.h>
using namespace std;
int n, i, p[6] = {50, 80, 170, 20, 200, 110};
int main() {
  scanf("%d", &n);
  if (n < 3) return cout << -1, 0;
  if (n == 3) return cout << 210, 0;
  printf("1");
  for (i = 1; i <= n - 4; i++) printf("0");
  if (p[(n % 6 + 2) % 6] < 100)
    printf("0%d", p[(n % 6 + 2) % 6]);
  else
    printf("%d", p[(n % 6 + 2) % 6]);
}
