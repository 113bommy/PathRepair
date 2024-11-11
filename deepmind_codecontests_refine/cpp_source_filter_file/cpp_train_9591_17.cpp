#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < k; i++) {
    int num0 = 0, num1 = 0, t = 0;
    for (int j = 1; j <= n; j++) {
      if (j == i + t * k) {
        t++;
        continue;
      } else {
        if (a[i] == 1) {
          num1++;
        } else {
          num0++;
        }
      }
    }
    ans = max(ans, abs(num1 - num0));
  }
  cout << ans << endl;
  return 0;
}
