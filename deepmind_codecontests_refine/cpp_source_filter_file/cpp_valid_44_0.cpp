#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (abs(a - b) == 1) {
      cout << "-1\n";
      continue;
    }
    if (a == 0 and b == 0) {
      cout << 0 << "\n";
      continue;
    }
    if (a == b or a == -b) {
      cout << 1 << "\n";
      continue;
    }
    cout << 2 << "\n";
  }
  return 0;
}
