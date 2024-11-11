#include <bits/stdc++.h>
using namespace std;
const int maxn = 100011;
const int modd = 1e9 + 9;
long long _pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2) ans = ans * a % modd;
    a = a * a % modd;
    b = b / 2;
  }
  return ans % modd;
}
int main(int argc, char const *argv[]) {
  long long n, m, k;
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  long long t = (n / k) * (k - 1) + n - (n / k) * k;
  if (m <= t)
    printf("%I64d\n", m);
  else {
    t = m - t;
    printf(
        "%I64d\n",
        (k * (_pow(2, t + 1) - 2 + modd) % modd + (m - t * k) % modd) % modd);
  }
  return 0;
}
