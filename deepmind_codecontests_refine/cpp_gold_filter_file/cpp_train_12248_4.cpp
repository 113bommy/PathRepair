#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1007;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  for (int k = 0; k * a <= n; k++) {
    int m = n - k * a;
    if (m % b != 0) continue;
    m /= b;
    int st = 1;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < a; j++) printf("%d ", st + (j + 1) % a);
      st += a;
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < b; j++) printf("%d ", st + (j + 1) % b);
      st += b;
    }
    printf("\n");
    return 0;
  }
  printf("-1\n");
  return 0;
}
