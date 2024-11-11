#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a, b, c, t, i, j, k;
  string s;
  cin >> n >> a >> b;
  cin >> c;
  long long ok[n - 1];
  for (i = 1; i <= n - 1; i++) cin >> ok[i - 1];
  sort(ok, ok + n - 1);
  j = 0, k = c;
  for (i = 1; i <= n - 1; i++) k += ok[i - 1];
  if (fabs(c * 1.0 * a) / k >= b) {
    cout << j;
    return 0;
  }
  for (i = n - 1; i > 0; i--) {
    k -= ok[i - 1], j++;
    if (fabs(c * 1.0 * a) / k >= b) {
      cout << j;
      return 0;
    }
  }
  return 0;
}
