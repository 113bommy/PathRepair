#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t;
  cin >> n >> k >> t;
  if (k <= t) {
    cout << t << endl;
  } else if (t <= n)
    cout << k << endl;
  else if (t <= n + k) {
    cout << n + k - t << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
