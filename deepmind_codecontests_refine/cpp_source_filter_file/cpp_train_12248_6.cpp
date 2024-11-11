#include <bits/stdc++.h>
using namespace std;
long long n, a, b, i = 0, x, j, k, arr[1000009], y;
int main(void) {
  cin >> n >> a >> b;
  for (i = 0; i <= n; i++) {
    if (i * a < n && (n - i * a) % b == 0) break;
  }
  if (i > n) return cout << -1, 0;
  x = i;
  j = 1;
  for (i = 0; i < x; i++) {
    y = j;
    for (k = 0; k < a - 1; k++) arr[j] = j + 1, j++;
    arr[j] = y, j++;
  }
  x = (n - a * x) / b;
  for (i = 0; i < x; i++) {
    y = j;
    for (k = 0; k < b - 1; k++) arr[j] = j + 1, j++;
    arr[j] = y, j++;
  }
  for (i = 1; i <= n; i++) cout << arr[i] << " ";
  return 0;
}
