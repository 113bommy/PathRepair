#include <bits/stdc++.h>
using namespace std;
int main() {
  string n;
  cin >> n;
  if (n.size() > 1) {
    int s = (n[n.size() - 2] - '0'),
        arr[3][4] = {{1, 2, 4, 3}, {1, 3, 4, 2}, {1, 4, 1, 4}};
    s *= 10;
    s += (n[n.size() - 1] - '0');
    int ans = 1;
    ans += arr[0][s % 4];
    ans += arr[1][s % 4];
    ans += arr[2][s % 4];
    cout << ans % 5;
  } else {
    int s = n[0] - '0', b = 1, c = 1, d = 1;
    for (int i = 0; i < s; i++) {
      b *= 2;
      c *= 3;
      d *= 4;
    }
    cout << (1 + b + c + d) % 5;
  }
}
