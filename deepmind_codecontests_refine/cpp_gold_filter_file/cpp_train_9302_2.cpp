#include <bits/stdc++.h>
using namespace std;
vector<int> g;
int i, n, d, l, j;
int main(int argc, const char* argv[]) {
  cin >> n >> d >> l;
  g.resize(n, 1);
  int sum1 = 0, sum2 = 0;
  sum1 = n / 2 + n % 2;
  sum2 = n / 2;
  for (j = 0; j <= abs(d); j++) {
    if (sum1 - sum2 == d) {
      break;
    }
    if (d > 0) {
      for (i = 0; i < n; i += 2) {
        if (sum1 - sum2 == d) {
          break;
        }
        g[i]++;
        sum1++;
      }
    } else {
      for (i = 1; i < n; i += 2) {
        if (sum1 - sum2 == d) {
          break;
        }
        g[i]++;
        sum2++;
      }
    }
  }
  int f = 0;
  for (i = 0; i < n; i++) {
    if (g[i] > l) {
      f = 1;
      break;
    }
  }
  if (sum1 - sum2 != d || f) {
    cout << -1;
    return 0;
  }
  for (i = 0; i < n; i++) {
    cout << g[i] << ' ';
  }
}
