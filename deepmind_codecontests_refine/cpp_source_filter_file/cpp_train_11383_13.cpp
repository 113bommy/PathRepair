#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int main() {
  int n, i, t, j;
  while (cin >> n) {
    memset(a, 0, sizeof(a));
    for (i = 1; i < n; i++) {
      t = 10000;
      a[i] = a[i] + t;
      j = i + (int)pow(2.0, floor(log((double)(n - i)) / log(2.0)));
      a[j] = a[j] + a[i];
    }
    cin >> t;
    a[0] = 0;
    for (i = 1; i < n; i++) {
      a[0] = a[0] + a[i];
      cout << a[0] << endl;
    }
  }
  return 0;
}
