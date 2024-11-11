#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k, x, y;
  long long int a[14], b[14];
  for (i = 0; i < 14; i++) {
    scanf("%lli", &a[i]);
    b[i] = a[i];
  }
  long long int ans;
  long long int max = 0;
  for (i = 0; i < 14; i++) {
    ans = 0;
    if (a[i] > 0) {
      k = a[i];
      a[i] = 0;
      x = k / 14;
      y = k % 14;
      j = i + 1;
      while (k > 0 && x > 0) {
        a[j % 14] += x;
        k -= x;
        j++;
      }
      j = i + 1;
      while (k > 0 && y > 0) {
        a[j % 14]++;
        k--;
        j++;
      }
      for (j = 0; j < 14; j++) {
        if (a[j] % 2 == 0) ans += a[j];
      }
      if (ans > max) max = ans;
      for (j = 0; j < 14; j++) {
        a[j] = b[j];
      }
    }
  }
  printf("%lli", max);
  return 0;
}
