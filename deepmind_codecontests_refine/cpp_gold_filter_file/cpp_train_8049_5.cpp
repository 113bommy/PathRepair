#include <bits/stdc++.h>
using namespace std;
int n;
int a[21000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int mx = -1000000000;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0 && n / i >= 3) {
      for (int j = 0; j < i; ++j) {
        int current = 0;
        for (int k = j; k < n; k += i) {
          current += a[k];
        }
        mx = max(current, mx);
      }
    }
  }
  printf("%d\n", mx);
  return 0;
}
