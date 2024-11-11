#include <bits/stdc++.h>
using namespace std;
long long a[111];
int main() {
  long long p, q;
  cin >> p >> q;
  int n, i;
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%I64d", a + i);
  if (n == 1) {
    if (p % q == 0 && p / q == a[1])
      puts("YES");
    else
      puts("NO");
    return 0;
  }
  if (a[n] == 1) a[n - 1]++, n--;
  for (i = 1; i <= n; i++) {
    if (p / q < a[i] || p / q > a[i]) {
      puts("NO");
      return 0;
    }
    p -= q * a[i];
    swap(p, q);
    if (q == 0 && i == n) {
      puts("YES");
      return 0;
    }
    if (q == 0 && i != n) {
      puts("NO");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
