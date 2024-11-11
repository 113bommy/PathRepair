#include <bits/stdc++.h>
using namespace std;
long long n, a[100], b[100], x = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (int i = 0; i < n; i++) {
    x = 0;
    while (a[i] > 0) {
      if (a[i] % b[i] == 0) {
        a[i] = a[i] / b[i];
        x++;
      } else {
        x = x + (a[i] % b[i]);
        a[i] = a[i] - (a[i] % b[i]);
      }
    }
    cout << x << endl;
  }
}
