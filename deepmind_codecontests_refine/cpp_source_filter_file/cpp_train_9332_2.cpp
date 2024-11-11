#include <bits/stdc++.h>
using namespace std;
long long f;
int main() {
  long long m, n, com;
  cin >> n >> m;
  long long i, j;
  long long a[n], b[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  long long comp = a[0] * b[0];
  long long x = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (comp < a[i] * b[j]) {
        comp = a[i] * b[j];
        x = i;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (i != x) {
      for (j = 0; j < m; j++) {
        if (f == 0) {
          com = a[i] * b[j];
          f = 1;
        } else {
          if (com < a[i] * b[j]) com = a[i] * b[j];
        }
      }
    }
  }
  cout << com;
  return 0;
}
