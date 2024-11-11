#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    if (!(i & 1)) {
      maxi += (m - 1) / 2 + 1;
    } else {
      maxi += m / 2;
    }
  }
  int maxi_4 = 0;
  int k = (n == 2 ? m : (m == 2 ? n : -1));
  for (int i = 0; i < k; i += 4) {
    if (i + 1 < k)
      maxi_4 += 4;
    else
      maxi_4 += 2;
  }
  maxi = max(maxi, maxi_4);
  printf("%d", max(max(n, m), maxi));
  return 0;
}
