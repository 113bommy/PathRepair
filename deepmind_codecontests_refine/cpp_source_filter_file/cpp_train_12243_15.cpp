#include <bits/stdc++.h>
using namespace std;
int reverse(int n) { return n % 10 * 10 + n / 10; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, m;
  char c;
  cin >> h >> c >> m;
  if (reverse(h) >= m && reverse(h) < 60) {
    cout << reverse(h) - m << '\n';
  } else if (h == 23) {
    cout << 60 - m << '\n';
  } else {
    int nh = h + 1;
    while (reverse(nh) > 60) nh++;
    cout << nh * 60 + reverse(nh) - h * 60 - m << '\n';
  }
  return 0;
}
