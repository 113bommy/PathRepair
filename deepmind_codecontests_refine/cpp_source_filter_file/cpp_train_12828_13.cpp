#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
void init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
int main() {
  init();
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    cout << max(0, min(n, x + y - n)) + 1 << " " << min(n, x + y - 1) << endl;
  }
  return 0;
}
