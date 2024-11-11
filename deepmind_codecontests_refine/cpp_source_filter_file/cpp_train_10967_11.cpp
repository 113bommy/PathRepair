#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int a[203] = {0};
  scanf("%d", &n);
  scanf("%d", &k);
  int x = 2 * n + 1, num;
  for (int i = 1; i <= x; i++) {
    scanf("%d", &num);
    a[i] = num;
  }
  for (int i = 1; i <= x; i++) {
    if (a[i] > a[i - 1] + 1 && a[i] > a[i + 1] + 1 && i % 2 == 0) {
      cout << a[i] - 1 << " ";
      k--;
    } else {
      cout << a[i] << " ";
    }
  }
  return 0;
}
