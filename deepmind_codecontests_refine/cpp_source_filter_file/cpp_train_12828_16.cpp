#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    cout << (x + y <= n ? 1 : x + y - n + 1) << " ";
    cout << (x + y > n ? n : x + y - 1) << endl;
  }
  return 0;
}
