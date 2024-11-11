#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, i, mx, cnt, ind, n, x, y;
  long long rec, B, t;
  cin >> n >> x >> y;
  if (n > y) {
    printf("-1\n");
    return 0;
  }
  B = y - (n - 1);
  t = x - (n - 1);
  if (B * B >= t) {
    for (i = 0; i < n - 1; i++) printf("1\n");
    cout << B << endl;
  } else
    printf("-1\n");
  return 0;
}
