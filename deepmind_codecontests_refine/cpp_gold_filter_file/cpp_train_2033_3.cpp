#include <bits/stdc++.h>
using namespace std;
long long a, b, n, q, x, mas[1000001];
bool fl;
int main() {
  scanf("%lld%lld", &n, &q);
  for (int i = 0; i < q; ++i) {
    scanf("%lld", &x);
    if (x == 1) {
      scanf("%lld", &x);
      if (x % 2) fl = !fl;
      a += x;
      b += x;
    } else {
      if (!fl) {
        a++;
        b--;
      } else {
        a--;
        b++;
      }
      fl = !fl;
    }
  }
  a = a % n;
  b = b % n;
  for (int i = 0; i < n; ++i)
    if (!(i % 2))
      mas[(i + a + n) % n] = i + 1;
    else
      mas[(i + b + n) % n] = i + 1;
  for (int i = 0; i < n; ++i) printf("%lld ", mas[i]);
}
