#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) {
      swap(a, b);
    }
    int result = b - a;
    if (c + r < a || c - r > b) {
      cout << result << endl;
      break;
    }
    result -= 2 * r;
    result += max(0, a - (c - r));
    result += max(0, c + r - b);
    cout << result << endl;
  }
}
