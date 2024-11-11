#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x, z = 0, k = 0;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x % 2 == 0) {
      z++;
    } else {
      k++;
    }
  }
  if (z == 0) {
    count += k / 2;
    cout << count;
    return 0;
  }
  if (k > z) {
    count += z;
    k -= z;
    count += k / 2;
    cout << count;
    return 0;
  } else {
    cout << k;
    return 0;
  }
  return 0;
}
