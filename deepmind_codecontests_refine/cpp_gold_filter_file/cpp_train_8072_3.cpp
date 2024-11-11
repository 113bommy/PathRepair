#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long int c = a[0], d = a[n - 1], i = 0, j = n - 1, t = 1;
  if (n == 1) {
    cout << 1 << " " << 0 << endl;
  } else {
    while (j - i != 1) {
      if (c <= d) {
        ++i;
        c += a[i];
        ++t;
      } else {
        --j;
        d += a[j];
      }
    }
    cout << t << " " << n - t << endl;
  }
}
