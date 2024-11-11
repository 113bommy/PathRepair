#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, y = 0, a[100000], b, l = 0;
  cin >> n >> t;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; ++i) {
    b = 86400 - a[i];
    y = y + b;
    if (y >= t) {
      break;
    }
    l++;
  }
  cout << l + 1;
  return 0;
}
