#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a < b ? b : a; }
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int bl = k - 1;
  int br = n - k;
  int divided = m / n - max(bl, br);
  int fp = (divided <= 0) ? 1 : divided;
  int minus = (divided <= 0) ? 1 : divided;
  m -= (divided <= 0) ? n : divided * n;
  while (m > 0) {
    int tmp = 1 + min(bl, fp - minus) + min(br, fp - minus);
    if (m - tmp >= 0) {
      fp++;
      m -= tmp;
    } else {
      break;
    }
  }
  cout << fp << endl;
  return 0;
}
