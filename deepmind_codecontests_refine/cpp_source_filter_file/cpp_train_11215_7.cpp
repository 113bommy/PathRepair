#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if ((n == 2 && a[0] == a[1]) || n == 1) {
    cout << -1;
    return 0;
  }
  int vogsum = 0;
  for (int i = 0; i < n; i++) {
    vogsum += a[i];
    sum -= a[i];
    if (sum != vogsum) {
      cout << i + 1 << endl;
      for (int j = 0; j <= i; j++) cout << a[j] << " ";
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
