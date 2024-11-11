#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t;
  cin >> n >> k >> t;
  int z = t * n * k / 100;
  if (z / k < n) {
    for (int i = 0; i < z / k; i++) cout << k << " ";
    cout << z - (z / k) * k << " ";
    int j = z / k + 1;
    while (j < n) {
      cout << 0 << " ";
      j++;
    }
  } else {
    for (int i = 0; i < n; i++) cout << k << " ";
  }
  return 0;
}
