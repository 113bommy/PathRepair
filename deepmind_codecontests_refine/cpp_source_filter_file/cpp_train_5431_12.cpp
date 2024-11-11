#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  float f[n];
  long long a[n];
  float d[n];
  for (long long i = 0; i < n; i++) {
    cin >> f[i];
    a[i] = int(f[i]);
    d[i] = f[i] - a[i];
  }
  long long dsum = 0;
  for (long long i = 0; i < n; i++) {
    dsum += a[i];
  }
  dsum = -dsum;
  if (dsum < 0) {
    for (long long i = 0; i < n; i++) {
      if (a[i] < 0 && d[i] != 0.0) {
        a[i] = a[i] - 1;
        dsum++;
      }
      if (dsum == 0) break;
    }
  } else if (dsum > 0) {
    for (long long i = 0; i < n; i++) {
      if (a[i] > 0 && d[i] != 0.0) {
        a[i]++;
        dsum--;
      }
      if (dsum == 0) break;
    }
  }
  for (long long i = 0; i < n; i++) cout << a[i] << "\n";
  return 0;
}
