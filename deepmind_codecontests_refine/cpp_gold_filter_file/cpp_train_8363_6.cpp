#include <bits/stdc++.h>
using namespace std;
int s[6];
int main() {
  int n, m, p;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    s[p]++;
  }
  int minf = 1 << 29;
  int ans3, ans4, ans5;
  for (int k3 = m / n; k3 >= 0; --k3) {
    int t3 = k3 * s[3];
    int last4 = 1 << 29;
    for (int k4 = (m - t3) / (s[4] + s[5]); k4 >= k3; --k4) {
      int t4 = k4 * s[4];
      if ((m - t3 - t4) % s[5] == 0) {
        int k5 = (m - t3 - t4) / s[5];
        if (abs(t3 - t4) + abs(t4 - k5 * s[5]) < last4) {
          last4 = abs(t3 - t4) + abs(t4 - k5 * s[5]);
          if (abs(t3 - t4) + abs(t4 - k5 * s[5]) < minf) {
            minf = abs(t3 - t4) + abs(t4 - k5 * s[5]);
            ans3 = k3;
            ans4 = k4;
            ans5 = k5;
          }
        } else
          break;
      }
    }
  }
  if (minf < (1 << 29))
    printf("%d %d %d\n", ans3, ans4, ans5);
  else
    printf("-1\n");
  return 0;
}
