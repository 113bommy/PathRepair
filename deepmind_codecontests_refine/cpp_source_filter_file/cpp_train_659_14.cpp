#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, k, n;
  cin >> y >> k >> n;
  int i = 0;
  bool b = false;
  for (int i = k; i < n; i += k) {
    if (i - y > 0) {
      cout << i << " ";
      b = true;
    }
  }
  if (!b) cout << -1;
  cout << endl;
  return 0;
}
