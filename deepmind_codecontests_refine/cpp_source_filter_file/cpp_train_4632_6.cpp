#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, p, x, y;
  cin >> n >> k >> p >> x >> y;
  int low = 0;
  int sum = 0;
  for (int ii = 0; ii < k; ii++) {
    int g;
    cin >> g;
    if (g <= y) {
      low++;
    }
    sum += g;
  }
  if (low > (n - 1) / 2) {
    puts("-1");
    return 0;
  }
  int rem = min(n - k, (n - 1) / 2 - low);
  if (sum + rem + (n - k - rem) * y > x)
    puts("-1");
  else {
    for (int ii = 0; ii < rem; ii++) printf("1 ");
    for (int ii = 0; ii < n - k - rem; ii++) printf("%d ", y);
    puts("");
  }
  return 0;
}
