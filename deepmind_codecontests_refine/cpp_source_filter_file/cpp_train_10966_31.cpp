#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k % n == 0) {
    int z = k / n;
    if (z > 2)
      cout << 0;
    else
      cout << n;
  } else {
    int z = k / n;
    if (z > 2)
      cout << 0;
    else if (z == 2) {
      cout << k % n;
    } else if (z < 2)
      cout << n;
  }
}
