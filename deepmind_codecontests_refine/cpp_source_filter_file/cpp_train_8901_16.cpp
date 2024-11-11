#include <bits/stdc++.h>
using namespace std;
int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 8, 7};
int main() {
  int x, y;
  cin >> x >> y;
  long long res = 0;
  for (int i = x; i <= y; ++i) {
    int cur = i;
    while (cur > 0) {
      res += a[cur % 10];
      cur /= 10;
    }
  }
  cout << res << "\n";
  return 0;
}
