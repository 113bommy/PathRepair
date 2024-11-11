#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *p = new int[100010];
  fill(p, p + 100010, -1000000000);
  for (int i = 0; i < n; ++i) {
    int x, y;
    int res = 0;
    scanf("%d%d", &x, &y);
    int q = (int)sqrt((double)x);
    for (int j = 1; j <= q; ++j) {
      if (x % j == 0) {
        if (p[j] < i - y) ++res;
        p[j] = i;
        if (p[x / j] < i - y) ++res;
        p[x / j] = i;
      }
    }
    cout << res << endl;
  }
  return 0;
}
