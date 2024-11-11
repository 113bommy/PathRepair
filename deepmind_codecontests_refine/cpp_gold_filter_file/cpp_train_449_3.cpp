#include <bits/stdc++.h>
using namespace std;
int n, T[5500], C[5500];
long long f[5500];
int main() {
  scanf("%d \n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d \n", &T[i], &C[i]);
  }
  f[0] = 0;
  for (int i = 1; i < 5500; i++) {
    f[i] = 1e18;
  }
  int tempt;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= 0; j--) {
      tempt = min(j + T[i] + 1, n);
      f[tempt] = min(f[tempt], f[j] + C[i]);
    }
  }
  printf("%I64d", f[n]);
  return 0;
}
