#include <bits/stdc++.h>
using namespace std;
int n, a[10000], b[100000];
long long m, c, d;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  if (n == 1) {
    cout << a[0] + b[0] << endl;
    return 0;
  }
  if (n == 2) {
    cout << (a[0] | a[1]) + (b[0] | b[1]) << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = i + 2; j < n; j++) {
      c = 0, d = 0;
      for (int l = i; l < j; l++) {
        c |= a[l];
        d |= b[l];
      }
      if (c + d > m) m = c + d;
    }
  cout << m << endl;
}
