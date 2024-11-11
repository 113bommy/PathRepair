#include <bits/stdc++.h>
using namespace std;
int f[3000100];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    f[i] = i;
  }
  int p = 0;
  for (int k = 2; k <= n; ++k) {
    f[p + n] = f[p + n / k * k];
    for (int i = n / k * k - k; i >= 0; i -= k) {
      f[p + i + k] = f[p + i];
    }
    ++p;
  }
  printf("%d", f[p] + 1);
  for (int i = 1; i < n; ++i) {
    printf(" %d", f[p + i] + 1);
  }
  printf("\n");
  return 0;
}
