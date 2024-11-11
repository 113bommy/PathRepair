#include <bits/stdc++.h>
using namespace std;
class retangle {
  int n;
  int x1, y1, x2, y2;

 public:
  void read() {
    cin >> n;
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
      cin >> x1 >> y1 >> x2 >> y2;
      cout << 2 * (abs(x1) % 2) + (abs(y1) % 2) + 1 << endl;
    }
  }
};
int main() {
  retangle r;
  r.read();
  return 0;
}
