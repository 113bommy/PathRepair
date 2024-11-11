#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[50], b[50], x, y, c = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] < a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        temp = b[j];
        b[j] = b[j + 1];
        b[j + 1] = temp;
      } else if (a[j] == a[j + 1] && b[j] > b[j + 1]) {
        temp = b[j];
        b[j] = b[j + 1];
        b[j + 1] = temp;
      }
    }
  }
  x = a[k - 1];
  y = b[k - 1];
  for (int i = 0; i < n; i++)
    if (x == a[i] && y == b[i]) c++;
  cout << c;
  return 0;
}
