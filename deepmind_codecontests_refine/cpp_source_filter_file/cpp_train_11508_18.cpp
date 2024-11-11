#include <bits/stdc++.h>
using namespace std;
vector<int> sum;
int main() {
  int n, d, h;
  cin >> n >> d >> h;
  if (d == 1) {
    if (n > 2) {
      cout << -1 << endl;
    } else {
      cout << "1 2" << endl;
    }
  } else {
    if (d - h > h) {
      cout << -1 << endl;
    } else {
      for (int i = 1; i <= h; i++) {
        cout << i << " " << i + 1 << endl;
      }
      if (d > h) cout << 1 << " " << h + 2 << endl;
      for (int i = h + 2; i <= d; i++) {
        cout << i << " " << i + 1 << endl;
      }
      for (int i = d + 2; i <= n; i++) {
        cout << 1 << " " << i << endl;
      }
    }
  }
  return 0;
}
