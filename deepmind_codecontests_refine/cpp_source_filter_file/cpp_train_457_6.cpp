#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, a[100], temp, max;
  while (cin >> n >> l) {
    max = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if (l <= a[n - 1]) {
      for (int i = l; i <= a[i]; i++) {
        temp = 0;
        for (int j = 0; j < n; j++) temp = temp + a[j] / i * i;
        if (temp > max) max = temp;
      }
    }
    cout << max << endl;
  }
  return 0;
}
