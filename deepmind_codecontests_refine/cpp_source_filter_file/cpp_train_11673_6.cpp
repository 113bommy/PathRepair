#include <bits/stdc++.h>
using namespace std;
double func(int n, int r, int b) {
  double ans = 0;
  int i;
  for (i = 1; i <= b; i++) {
    ans += (((n - r + i) * 1.0) / (n + i));
  }
  return ans;
}
int main() {
  int n, m, h;
  cin >> n >> m >> h;
  int ara[m], i, total = 0;
  for (i = 0; i < m; i++) {
    cin >> ara[i];
    if (i + 1 != h) total += ara[i];
  }
  if (total + ara[h - 1] < n) {
    cout << -1 << endl;
    return 0;
  }
  if (total < n - 1) {
    cout << 1 << endl;
    return 0;
  }
  if (ara[h - 1] == 1) {
    cout << 0 << endl;
    return 0;
  }
  cout << fixed << setprecision(15) << 1 - func(total, n - 1, ara[h - 1] - 1)
       << endl;
  return 0;
}
