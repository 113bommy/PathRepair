#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long lf, rg;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &lf, &rg);
    ++rg;
    int j = 0;
    while ((rg >> 1) > (lf >> 1)) {
      rg >>= 1;
      lf >>= 1;
      ++j;
    }
    while (j > 0) {
      --j;
      lf <<= 1;
      lf |= 1;
    }
    printf("%d\n", lf);
  }
  return 0;
}
