#include <bits/stdc++.h>
using namespace std;
int n, flag;
double p[102], ans;
int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 0; n - 2 * i > 0; i++) {
    for (int j = n; n - 2 * j < 0; j--) {
      ans = max(ans, (p[i] * (2 * j - n) + p[j] * (n - 2 * i)) / (2 * (j - i)));
    }
  }
  cout << ans;
  return 0;
}
