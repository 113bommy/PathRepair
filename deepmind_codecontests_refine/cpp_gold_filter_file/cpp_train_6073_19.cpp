#include <bits/stdc++.h>
using namespace std;
int a[1000001], i, j, k, t, ans, n, m;
int main() {
  cin >> n;
  for (i = 2; i <= 1000000; i++)
    if (!a[i])
      for (j = i + i; j <= 1000000; j += i) a[j] = 1;
  for (i = 2; i <= 1000000; i++) {
    if (a[i]) continue;
    j = i;
    t = 0;
    while (j > 0) {
      t = 10 * t + j % 10;
      j /= 10;
    }
    if (i != t && !a[t]) m++;
    if (m == n) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
