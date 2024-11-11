#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 100000000, a[101];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++)
      sum += 2 * a[j] * (abs(j - i) + abs(i - 1) + abs(j - 1));
    ans = min(ans, sum);
  }
  cout << ans;
}
