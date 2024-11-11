#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i;
  cin >> n >> a >> b;
  if (n == 1 && a == 0 && b == 0) {
    cout << 1;
    return 0;
  }
  if (b == 0 && a == n - 1) {
    cout << -1;
    return 0;
  }
  if (b == 0 && a < n - 1 && a > 0) {
    int tmp = 1;
    cout << 20 << " " << (++tmp);
    for (i = 0; i < a; i++) cout << " " << (++tmp);
    for (i = 0; i < n - 1 - a; i++) cout << " " << 1;
    return 0;
  }
  int arr[110] = {1, 1}, sum = 1, maxx = 1;
  for (i = 2; i <= n; i++) {
    if (b > 0) {
      arr[i] = sum + 1;
      maxx = arr[i];
      sum += arr[i];
      b--;
      if (arr[i] > 50000) {
        cout << -1;
        return 0;
      }
      continue;
    }
    if (a > 0) {
      arr[i] = maxx + 1;
      maxx++;
      sum += arr[i];
      a--;
      if (arr[i] > 50000) {
        cout << -1;
        return 0;
      }
      continue;
    }
    arr[i] = 1;
  }
  cout << arr[1];
  for (i = 2; i <= n; i++) cout << " " << arr[i];
}
