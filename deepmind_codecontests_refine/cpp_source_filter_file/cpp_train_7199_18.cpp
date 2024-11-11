#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int inf = 0x3f3f3f3f;
int a[2][maxn];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >> n;
  int m1 = 0, k1 = 0;
  for (int i = (1); i < (n + 1); i++) cin >> a[0][i];
  for (int i = (1); i < (n + 1); i++) {
    cin >> a[1][i];
    if (a[1][i]) m1 = max(i - a[1][i] + 1, m1);
    if (a[1][i] == 1) k1 = i;
  }
  if (k1) {
    int flag = 1;
    for (int i = k1 + 1; i <= n; i++)
      if (a[1][i] - a[1][i - 1] > 1) flag = 0;
    if (flag) {
      for (int i = (1); i < (k1); i++) {
        if (!a[1][i]) continue;
        if (i >= a[1][i] - a[1][n]) flag = 0;
      }
      if (flag) {
        cout << n - a[1][n] << endl;
        return 0;
      }
    }
  }
  cout << m1 + n << endl;
  return 0;
}
