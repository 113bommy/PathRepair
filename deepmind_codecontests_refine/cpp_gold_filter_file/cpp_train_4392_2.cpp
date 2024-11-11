#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int N = a + b;
  int res = 0;
  int l = 1;
  while (l <= N) {
    int g = N / l;
    int r = N / g;
    if (a < g || b < g) {
      l = r + 1;
      continue;
    }
    int a_low = (a + g) / (g + 1);
    int a_high = a / g;
    int b_low = (b + g) / (g + 1);
    int b_high = b / g;
    if (a_low <= a_high && b_low <= b_high) {
      res += max(0, min(r, a_high + b_high) - max(l, a_low + b_low) + 1);
    }
    l = r + 1;
  }
  cout << res << endl;
  return 0;
}
