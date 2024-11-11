#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  cin >> n >> k;
  if (((n * (n - 1)) >> 1) <= k) {
    cout << "no solution";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cout << i << ' ' << 1000000000 - i * 3000 << endl;
  }
}
