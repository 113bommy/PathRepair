#include <bits/stdc++.h>
using namespace std;
long long a[300000];
int main() {
  long long n, w = 0, b = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      w += a[i] / 2;
      b += a[i] / 2;
    } else {
      w += a[i] / 2;
      b += a[i] / 2;
      if (i % 2)
        w++;
      else
        b++;
    }
  }
  cout << min(w, b);
  return 0;
}
