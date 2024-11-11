#include <bits/stdc++.h>
using namespace std;
int main() {
  float a, ans = 0;
  int n;
  cin >> n;
  for (int b = 1; b <= n; b++) {
    float k, j;
    cin >> j >> k;
    ans = ans + k;
  }
  ans = ans / n + 5;
  cout << setprecision(3) << ans << endl;
}
