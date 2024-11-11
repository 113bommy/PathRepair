#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool prime[N];
int n, col[N];
int main() {
  scanf("%d", &n);
  n++;
  for (int i = 2; i <= n; i++) {
    for (int j = 2, lim = sqrt(i); j <= lim; j++)
      if (i % j == 0) col[i] = 2;
    if (col[i] != 2) col[i] = 1;
  }
  printf("%d\n", *max_element(col + 2, col + n + 1));
  for (int i = 2; i <= n; i++) printf("%d%c", col[i], i == n ? '\n' : ' ');
  return 0;
}
