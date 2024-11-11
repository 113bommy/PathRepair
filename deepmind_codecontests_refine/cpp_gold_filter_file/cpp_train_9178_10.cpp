#include <bits/stdc++.h>
using namespace std;
int main() {
  long long H, L;
  while (~scanf("%I64d %I64d", &H, &L)) {
    printf("%lf\n", (L * L - H * H) / (2 * 1.0 * H));
  }
  return 0;
}
