#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  if ((n > y) || ((n - 1) + (y - n + 1) * (y - n + 1) < x)) {
    cout << "-1";
  } else {
    for (int i = 1; i < n; ++i) {
      cout << "1" << endl;
    }
    cout << y - n + 1;
  }
}
