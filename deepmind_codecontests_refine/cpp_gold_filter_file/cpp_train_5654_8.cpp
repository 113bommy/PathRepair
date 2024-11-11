#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  int ans[105];
  cin >> n >> a >> b;
  if (n == a + 1 && b == 0 && n != 1) {
    cout << -1 << endl;
    return 0;
  }
  ans[1] = 1;
  int res = 1, sum = 1;
  for (int i = 2; i <= n; ++i) {
    if (b) {
      res = sum + 1;
      b--;
    } else if (a && i > 2) {
      res++;
      a--;
    }
    ans[i] = res;
    sum += res;
  }
  if (res > 50000) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i < n; ++i) printf("%d ", ans[i]);
  printf("%d\n", ans[n]);
  return 0;
}
