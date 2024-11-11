#include <bits/stdc++.h>
using namespace std;
int x[10100];
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    int c, sum;
    cin >> c >> sum;
    if (c > sum) {
      cout << sum << endl;
      continue;
    } else {
      memset(x, 0, sizeof(x));
      int num = 1;
      while (sum != 0) {
        x[num]++;
        num++;
        sum--;
        if (num == c + 1) num = 1;
      }
      long long ans = 0;
      for (int i = 1; i <= c; i++) {
        ans += x[i] * x[i];
      }
      cout << ans << endl;
    }
  }
  return 0;
}
