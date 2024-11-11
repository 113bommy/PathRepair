#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int M = 4e5;
const int lim = 1e3;
const int p = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long f[55], k;
int a[55], n;
int main() {
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= 50; i++) f[i] = f[i - 1] + f[i - 2];
  for (int i = 1; i <= 50; i++) a[i] = i;
  scanf("%d%lld", &n, &k);
  k--;
  for (int i = 1; i <= n;) {
    if (k < f[n - i])
      i++;
    else {
      swap(a[i], a[i + 1]);
      k -= f[n - i];
      i += 2;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
