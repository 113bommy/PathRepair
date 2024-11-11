#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005];
int main() {
  int n, x;
  cin >> n >> x;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  int flag = 0;
  for (int i = 0; i <= 9; i++) {
    a[1] = i;
    b[1] = 0;
    for (int j = 2; j <= n; j++) {
      int sum = a[j - 1] * x + b[j - 1];
      b[j] = sum / 10;
      a[j] = sum % 10;
    }
    int sum = a[n] * x + b[n];
    if (a[n] != 0 && sum / 10 == 0 && sum % 10 == a[1]) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    for (int i = n; i >= 1; i--) cout << a[i];
    cout << endl;
  } else
    cout << "Impossible" << endl;
}
