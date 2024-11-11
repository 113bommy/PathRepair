#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, temp = 0, y;
  cin >> n >> m;
  int sum = n * (n + 1) / 2;
  int l = m / sum;
  if (l > 0) {
    m = m - (l * sum);
  }
  for (i = 1; i <= n; i++) {
    int a = i * (i + 1) / 2;
    if (a > m) {
      y = i - 1;
      temp = 1;
      break;
    }
  }
  if (temp == 1) {
    cout << m - (y * (y + 1) / 2);
    return 0;
  }
}
