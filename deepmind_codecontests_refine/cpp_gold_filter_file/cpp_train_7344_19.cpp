#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, b, d, e, i, c = 0, wo = 0;
  cin >> n;
  cin >> b;
  cin >> d;
  vector<long long int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    e = 0;
    if (a[i] <= b) {
      c = c + a[i];
      e++;
    }
    if ((e == 1) && (c > d)) {
      wo++;
      c = 0;
    }
  }
  cout << wo;
  return 0;
}
