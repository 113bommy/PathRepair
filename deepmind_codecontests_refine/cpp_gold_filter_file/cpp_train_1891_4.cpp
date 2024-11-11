#include <bits/stdc++.h>
using namespace std;
const long long N = 5e3 + 10;
const double eps = 1e-13;
long long s[10], a[] = {4, 8, 15, 16, 23, 42};
signed main() {
  for (long long i = 1; i <= 4; i++) {
    printf("? %lld %lld\n", i, i + 1);
    fflush(stdout);
    scanf("%lld", &s[i]);
  }
  do {
    if (a[0] * a[1] == s[1] && a[1] * a[2] == s[2] && a[2] * a[3] == s[3] &&
        a[3] * a[4] == s[4])
      break;
  } while (next_permutation(a, a + 6));
  printf("!");
  for (long long i = 0; i < 6; i++) printf(" %lld", a[i]);
  cout << endl;
  return 0;
}
