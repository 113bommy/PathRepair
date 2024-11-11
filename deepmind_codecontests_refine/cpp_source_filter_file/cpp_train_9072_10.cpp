#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    cout << 1 << " " << 1 << endl;
  } else if (n == 2 || n == 3) {
    cout << 2 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 2 << endl;
    if (n == 3) {
      cout << 2 << " " << 2 << endl;
    }
  } else {
    int ans = (n - 3) / 2 + (n - 3) % 2 + 2;
    cout << ans << endl;
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 2 << endl;
    cout << 2 << " " << 2 << endl;
    int tmp = n - 2;
    int r = 2;
    int c = 3;
    for (int i = 1; i <= tmp; i++) {
      cout << r << " " << c << endl;
      if (i % 2 == 1) {
        r++;
      } else {
        c++;
      }
    }
  }
}
