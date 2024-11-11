#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int main(void) {
  int n;
  long long k;
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  long long s = 1ll * n * (n + 1) / 2;
  if (s > k) {
    puts("-1");
    return 0;
  }
  for (int i = 1, j = n; i <= n; i++) {
    if (j > i && s + j - i <= k) {
      swap(a[i], a[j]);
      s += j - i;
      j--;
    }
  }
  printf("%lld\n", s);
  for (int i = 1; i <= n; i++) {
    printf("%d%c", i, "\n "[i != n]);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d%c", a[i], "\n "[i != n]);
  }
}
