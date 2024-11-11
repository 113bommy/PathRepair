#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, e = 0, aw = 0, k = 0;
  cin >> n;
  long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    k = max(a[i], k);
    e += a[i];
  }
  aw = k * n - e;
  while (aw < e) {
    k++;
    aw = k * n - e;
  }
  cout << k;
  return 0;
}
