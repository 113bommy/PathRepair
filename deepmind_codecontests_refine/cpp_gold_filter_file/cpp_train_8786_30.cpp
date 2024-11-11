#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int m;
  cin >> m;
  int arr[m];
  int sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  int g = arr[m - 1], b = sum - g;
  int x, y;
  cin >> x >> y;
  for (int i = m - 1; i > 0; i--) {
    if (g < x || g > y || b > y || b < x) {
      b -= arr[i - 1];
      g += arr[i - 1];
    } else {
      cout << i + 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
