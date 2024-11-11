#include <bits/stdc++.h>
using namespace std;
const int MODN = 1e9 + 7;
int ns[5005];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ns[i]);
    ns[i] += ns[i - 1];
  }
  double rs = 0.0000000;
  for (int i = k; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j >= i) {
        rs = max(rs, (double)(ns[j] - ns[j - k]) / i);
      }
    }
  }
  printf("%.7f\n", rs);
  return 0;
}
