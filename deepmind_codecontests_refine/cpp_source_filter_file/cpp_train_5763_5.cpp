#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 20;
const double PI = M_PI;
const double EPS = 1e-15;
int R, C;
long long sum_i;
long long sum_j;
long long sum_i2;
long long sum_j2;
long long sum_c;
int main() {
  cin.sync_with_stdio(false);
  cin >> R >> C;
  for (int i = 1; i <= R; i++)
    for (int j = 1; j <= C; j++) {
      long long c;
      cin >> c;
      long long x = 4 * i - 2;
      long long y = 4 * j - 2;
      sum_i = sum_i + c * x;
      sum_j = sum_j + c * y;
      sum_i2 = sum_i2 + c * x * x;
      sum_j2 = sum_j2 + c * y * y;
      sum_c = sum_c + c;
    }
  int r = -1, c = -1;
  long long answer = (1LL << 62LL);
  for (int i = 1; i <= R; i++)
    for (int j = 1; j <= C; j++) {
      long long x = 4 * i;
      long long y = 4 * j;
      long long calc = sum_c * (x * x + y * y) - (2 * x * sum_i) -
                       (2 * y * sum_j) + sum_i2 + sum_j2;
      if (calc < answer) {
        r = i;
        c = j;
        answer = calc;
      }
    }
  cout << answer << endl;
  cout << r << " " << c << endl;
  return 0;
}
