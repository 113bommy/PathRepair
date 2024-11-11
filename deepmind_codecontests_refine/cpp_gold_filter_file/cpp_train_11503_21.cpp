#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = (int)1e5 + 10;
int a[N], b[N];
int abs(int x) { return x > 0 ? x : -x; }
int main() {
  scanf("%d%d", &m, &n);
  for (int i(0); (i) < (int)(n); i++) scanf("%d%d", &a[i], &b[i]);
  int ans = b[0] + a[0] - 1;
  ans = max(ans, b[n - 1] + m - a[n - 1]);
  for (int i(0); (i) < (int)(n); i++)
    if (i) {
      if (abs(b[i] - b[i - 1]) > a[i] - a[i - 1]) {
        ans = -1;
        break;
      }
      ans = max(ans, (a[i] - a[i - 1] - abs(b[i] - b[i - 1])) / 2 +
                         max(b[i], b[i - 1]));
    }
  if (ans == -1)
    puts("IMPOSSIBLE");
  else
    cout << ans << endl;
  return 0;
}
