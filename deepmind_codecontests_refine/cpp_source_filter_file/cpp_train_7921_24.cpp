#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int t1[] = {0, 0, 0, 0, 1, 2};
int t2[] = {0, 0, 0, 4, 8, 10, 12, 12};
int main() {
  long long n, m;
  scanf("%I64d%I64d", &n, &m);
  if (n > m) swap(n, m);
  long long x = 0;
  if (n == 1) {
    x = m / 6 + t1[m % 6];
  } else if (n == 2) {
    if (m <= 6)
      x = t2[m];
    else
      x = m * 2;
  } else {
    x = n * m / 2 * 2;
  }
  printf("%I64d\n", x);
}
