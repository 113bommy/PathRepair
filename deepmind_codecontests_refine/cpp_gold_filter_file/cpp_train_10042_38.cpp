#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a[] = {0,   1,   3,   6,   10,  15,  21,  28,  36,  45,  55,  66,  78,
             91,  105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325,
             351, 378, 406, 435, 465, 496, 528, 561, 595, 630, 666};
  int n;
  cin >> n;
  for (int i = 0; i < 37; ++i) {
    if (a[i] == n) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
