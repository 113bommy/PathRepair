#include <bits/stdc++.h>
using namespace std;
const int N = 5e7 + 5;
int n, k;
int ar[N];
int main() {
  scanf("%d %d", &n, &k);
  n *= 2;
  for (int i = 1; i <= n; i++) {
    ar[i] = i;
  }
  if (k) {
    for (int i = 1; i <= 2 * k; i += 2) {
      swap(ar[i + 1], ar[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ar[i]);
  }
  return 0;
}
