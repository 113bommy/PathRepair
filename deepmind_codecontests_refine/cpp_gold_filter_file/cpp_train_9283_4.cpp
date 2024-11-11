#include <bits/stdc++.h>
using namespace std;
long long a[1000002];
int ct = 0;
int main() {
  long long t;
  cin >> t;
  if (!(t & 1)) {
    cout << "NO" << endl;
    return 0;
  } else
    cout << "YES" << endl;
  for (int i = 1; i <= t; i++) {
    if (i & 1) {
      a[i] = ++ct, a[i + t] = ++ct;
    } else {
      a[i + t] = ++ct, a[i] = ++ct;
    }
  }
  for (int i = 1; i <= t * 2; i++) cout << a[i] << " ";
}
