#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> vec[150];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t, i, j, u, v, x, k, p, c, y, a, b, n, w;
  cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < 5; j++) {
      cin >> x;
      vec[i].push_back(x);
    }
  }
  int low = 0, high = 1000000007, ind = -1;
  for (int mid = 0; mid <= 1000; mid++) {
    long double ans1 = 0, ans2 = 0;
    cout << fixed;
    cout << setprecision(2);
    for (j = 0; j < 5; j++) {
      int cnt = 0;
      for (i = 1; i <= n; i++) {
        if (vec[i][j] != -1) {
          cnt++;
        }
      }
      int num, den;
      if (vec[1][j] == -1 && vec[2][j] != -1) {
        num = cnt;
        den = n + mid;
      } else if (vec[1][j] != -1 && vec[2][j] == -1) {
        num = cnt;
        den = n + mid;
      } else {
        if (vec[1][j] <= vec[2][j]) {
          num = cnt;
          den = n + mid;
        } else {
          num = cnt + mid;
          den = n + mid;
        }
      }
      long double val = 0;
      double val2 = (num * 1.0) / den;
      if (val2 >= 0 && val2 <= (0.03125)) {
        val = 3000;
      } else if (val2 > (0.03125) && val2 <= (0.0625))
        val = 2500;
      else if (val2 > 0.0625 && val2 <= (0.125))
        val = 2000;
      else if (val2 > 0.125 && val2 <= 0.25)
        val = 1500;
      else if (val2 > 0.25 && val2 <= 0.5)
        val = 1000;
      else
        val = 500;
      if (vec[1][j] != -1) ans1 += ((val * 1.0 * (250 - vec[1][j])) / 250);
      if (vec[2][j] != -1) ans2 += ((val * 1.0 * (250 - vec[2][j])) / 250);
    }
    if (ans1 > ans2) {
      ind = mid;
      break;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  cout << ind;
}
