#include <bits/stdc++.h>
using namespace std;
long long int i, j, k, n, h, m, s, t, a[100009], d, p, b[120009], q;
int main() {
  map<long long int, long long int> v;
  cin >> n;
  int c[9] = {0};
  for (i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i]]++;
  }
  h = 2;
  for (i = 0; i <= 28; i++) b[i] = pow(h, i);
  for (i = 0; i < n; i++) {
    for (j = 0; j <= 28; j++) {
      if (b[j] >= a[i]) {
        d = b[j] - a[i];
        if (d == a[i]) {
          if (v[d] >= 2) {
            a[i] = -1;
            break;
          }
        } else {
          if (v[d] >= 1) {
            a[i] = -1;
            break;
          }
        }
      }
    }
  }
  for (i = 0; i < n; i++)
    if (a[i] == -1) p++;
  cout << n - p << endl;
}
