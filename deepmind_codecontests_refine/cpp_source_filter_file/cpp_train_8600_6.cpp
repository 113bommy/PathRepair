#include <bits/stdc++.h>
using namespace std;
int ans[179] = {-1, -1, -1, 1, -1, 1, -1, 2, 1, 2, -1, 3, 2, 3};
int main() {
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int n;
    cin >> n;
    if (n < 15) {
      cout << ans[n - 1] << endl;
    } else {
      if (n % 4 == 0) {
        cout << n / 2 << endl;
      } else if (n % 4 == 1) {
        cout << n / 4 - 1 << endl;
      } else if (n % 4 == 2) {
        cout << n / 4 << endl;
      } else {
        cout << n / 4 - 2 << endl;
      }
    }
  }
}
