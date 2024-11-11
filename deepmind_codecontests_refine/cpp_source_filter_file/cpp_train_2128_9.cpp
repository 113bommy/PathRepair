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
  int aux = 1;
  if (k > n) {
    n--;
    n2 -= 2;
    aux = k - n;
    printf("%d %d pp", aux, 2 * aux);
  }
  for (int i = 2 * aux; i < 2 * aux + n2; i++) printf("%d ", i);
  return 0;
}
