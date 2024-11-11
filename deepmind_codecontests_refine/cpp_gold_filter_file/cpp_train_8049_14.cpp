#include <bits/stdc++.h>
using namespace std;
int a[10000001];
int main() {
  int n, ans = -1e9;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i * 3 <= n; i++) {
    if (n % i == 0) {
      for (int j = 1; j <= i; j++) {
        int sum = 0;
        for (int k = j; k <= n; k += i) {
          sum += a[k];
        }
        ans = max(ans, sum);
      }
    }
  }
  cout << ans;
  return 0;
}
