#include <bits/stdc++.h>
using namespace std;
int ar[100005];
long long ar2[100005];
void smpl(long long a, long long b) {
  long long i, x, sv, z = a;
  x = b;
  for (i = 1; i * i <= b; i++) {
    if (b % i != 0) continue;
    sv = b / i;
    if (i != 1)
      while (a % i == 0 && b % i == 0) {
        a /= i;
        b /= i;
      }
    if (sv != 1)
      while (a % sv == 0 && b % sv == 0) {
        a /= sv;
        b /= sv;
      }
  }
  if (a < 0) printf("%I64d\n", z);
  printf("%I64d %I64d\n", a, b);
}
int main() {
  long long sm = 0, y = 0, x = 0, z = 0, i, n;
  scanf("%I64d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &ar2[i]);
  }
  sort(ar2, ar2 + n);
  for (i = 0; i < n; i++) {
    ar[i] = ar2[i];
    z += ar[i] * i;
    y += ar[i];
  }
  x = y * (1 - n) + 2 * z;
  smpl(2 * x + y, n);
}
