#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[10001], n;
  cin >> n;
  if (n < 4) {
    cout << 1 << endl;
    return 0;
  }
  a[1] = 1;
  for (int i = 2; i <= n; i++) {
    a[i] = i + a[i - 1];
  }
  int sum = 0;
  for (int i = 1; i < n; i++) {
    sum += a[i];
    if (sum == n) {
      cout << i << endl;
      break;
    }
    if (sum > n) {
      cout << i - 1 << endl;
      break;
    }
  }
  return 0;
}
