#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long int a[t], b[t];
  for (int i = 0; i < t; i++) {
    cin >> a[i] >> b[i];
  }
  int m = 0, n = 0;
  for (int i = 0; i < t; i++) {
    if ((a[i] > 0) && (b[i] > 0) || ((a[i] > 0) && (b[i] < 0))) {
      m++;
    } else {
      n++;
    }
  }
  if ((m + 1 == t) || (n + 1 == t) || (m == t) || (n == t)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
