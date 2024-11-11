#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, m, k, s[1005], d[1005];
  while (~scanf("%d%d", &m, &k)) {
    for (i = 0; i < m; i++) {
      scanf("%d", &d[i]);
    }
    for (i = 0; i < m; i++) {
      scanf("%d", &s[i]);
    }
    int sum = 0, maxn = 0, f = 0;
    for (i = 0; i < m; i++) {
      f += s[i];
      if (s[i] > maxn) maxn = s[i];
      if (f < d[i]) {
        while (f < d[i]) {
          sum += k;
          f += maxn;
        }
      }
      sum += d[i];
      f -= d[i];
    }
    cout << sum << endl;
  }
  return 0;
}
