#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, k, a, b, c, d;
int main() {
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  if (k < n + 1 || n <= 4) {
    cout << -1 << endl;
  } else {
    printf("%d %d ", a, d);
    for (int i = 1; i <= n; i++)
      if (i != a && i != b && i != c && i != d) {
        printf("%d ", i);
      }
    printf("%d %d\n", c, b);
    printf("%d %d ", d, a);
    for (int i = 1; i <= n; i++)
      if (i != a && i != b && i != c && i != d) {
        printf("%d ", i);
      }
    printf("%d %d\n", b, c);
  }
  return 0;
}
