#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (k > m + n - 2) {
    cout << -1;
    printf("\n");
    return 0;
  }
  long long t1 = max(m, n), an1, an2;
  if (k <= t1 - 1) {
    an1 = m / (k + 1) * n;
    an2 = n / (k + 1) * m;
    printf("%I64d\n", max(an1, an2));
    return 0;
  }
  an1 = n / (k - m + 2), an2 = m / (k - n + 2);
  printf("%I64d\n", max(an1, an2));
  return 0;
}
