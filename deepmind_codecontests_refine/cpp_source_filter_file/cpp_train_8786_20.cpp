#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, x, y, sum = 0;
  cin >> n;
  int s[n], r[n];
  for (i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
    r[i] = sum;
  }
  cin >> x >> y;
  if (n <= 2)
    cout << 0;
  else {
    for (i = 1; i < n; i++) {
      j = r[i - 1];
      k = sum - j;
      if (j >= x && k >= x && j <= y && k <= y) {
        cout << i + 1;
        return 0;
      }
    }
  }
  cout << 0;
  return 0;
}
