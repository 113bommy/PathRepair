#include <bits/stdc++.h>
using namespace std;
int i, j, k, m;
unsigned long long p, f[20], s[20], an;
int main() {
  scanf("%I64u", &p);
  f[0] = 0;
  s[0] = 1;
  for (i = 0; i <= 18; i++)
    for (j = 0; j <= 9; j++) {
      s[i + 1] = (s[i + 1] + s[i]) % p;
      f[i + 1] = (s[i] * j + f[i] + f[i + 1]) % p;
    }
  an = (1 + f[18]) % p;
  unsigned long long t = (p - an) % p;
  printf("%I64u %I64u\n", t + 1, t + (unsigned long long)1e19);
  return 0;
}
