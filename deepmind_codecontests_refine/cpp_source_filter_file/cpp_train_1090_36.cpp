#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  bool bl = 0;
  long long m, o = 0;
  scanf("%d%I64d", &n, &m);
  --m;
  for (int i = n - 1; ~i; --i, bl ^= 1)
    if ((m & 1L << i) > 0 ^ bl) {
      o += (1L << i + 1) - 1;
      bl ^= 1;
    }
  printf("%I64d\n", o + n);
}
