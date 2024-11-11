#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1061109567;
const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int a[105][105];
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  if (x * y < n) {
    puts("-1");
    return 0;
  }
  int cnt1 = 1, cnt2 = 2;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (((i + j) & 1) && cnt1 <= n) {
        a[i][j] = cnt1;
        cnt1 += 2;
      } else if (((i + j) % 2 == 0) && cnt2 <= n) {
        a[i][j] = cnt2;
        cnt2 += 2;
      }
    }
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
