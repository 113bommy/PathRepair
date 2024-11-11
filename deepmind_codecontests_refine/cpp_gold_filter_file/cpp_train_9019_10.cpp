#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, l, m, n, a, b, c, d, x, y, z, tc, ans, num[1000005], w,
      lastNum, v1, v2, p, t;
  string inputA, inputB;
  while (cin >> n) {
    bool willWin = true;
    if (n == 5) {
      willWin = false;
      long long int nums[5] = {0};
      for (i = 0; i < n; i++) {
        cin >> a >> b;
        ++nums[a - 1];
        ++nums[b - 1];
      }
      for (i = 0; i < 5; i++) {
        if (nums[i] != 2) {
          willWin = true;
          break;
        }
      }
    } else {
      for (i = 0; i < n; i++) {
        cin >> a >> b;
      }
    }
    std::cout << (willWin ? "WIN" : "FAIL") << std::endl;
  }
  return 0;
}
