#include <bits/stdc++.h>
inline int Rand() { return (rand() << 16) | rand(); }
using namespace std;
long long n, d[1000001];
int main() {
  srand(time(NULL));
  scanf("%I64d", &n);
  d[3] = 1;
  for (int i = 4; i <= n; i++) d[i] = d[i - 1] + 2 * (i - 3) + 1;
  printf("%I64d", d[n]);
  return 0;
}
