#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, x, y, i, m, k, sum = 0;
  vector<int> sums;
  cin >> m;
  sums.resize(m + 1);
  for (i = 1; i <= m; ++i) {
    cin >> p;
    sum += p;
    sums[i] = sums[i - 1];
    sums[i] += p;
  }
  cin >> x >> y;
  int flag = 0;
  for (i = 1; i <= m; ++i) {
    int r1 = sums[i - 1];
    int r2 = sum - sums[i - 1];
    if (r1 >= x && r2 >= x && r1 <= y && r2 <= y) {
      cout << i;
      flag = 1;
      break;
    }
  }
  if (flag == 0) cout << 0;
  return 0;
}
