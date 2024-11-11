#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int n2 = n;
  n /= 2;
  if (k == 0 && n2 == 1) {
    printf("%d", 1);
    return 0;
  }
  if (n > k || !n) {
    cout << -1;
    return 0;
  }
  int aux = 0;
  if (k > n) {
    n--;
    aux = k - n;
    printf("%d %d ", aux, 2 * aux);
  }
  int i = 1;
  while (n) {
    if (i != aux && i != aux * 2 && i + 1 != aux && i + 1 != aux * 2) {
      printf("%d %d ", i, i + 1);
      i += 2;
      n--;
    } else
      i++;
  }
  if (n2 % 2) {
    while (i == aux || i == 2 * aux) i++;
    printf("%d", i);
  }
  return 0;
}
