#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  int a[110];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int ans = sum;
  for (int i = 0; i < n; i++) {
    int x = 0;
    int y = 0;
    for (int j = i; j < n; j++) {
      x += a[j];
      y += 1 - a[j];
      ans = max(ans, sum - x + y);
    }
  }
  cout << ans;
  return 0;
}
