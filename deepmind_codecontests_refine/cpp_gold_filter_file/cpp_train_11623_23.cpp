#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, v3, v4;
  cin >> v1 >> v2 >> v3 >> v4;
  if (v4 > 2 * v3 || v3 > 2 * v4 || v4 >= v2) {
    cout << -1 << "\n";
    return 0;
  }
  cout << 2 * v1 << "\n" << 2 * v2 << "\n" << max(v3, v4) << "\n";
}
