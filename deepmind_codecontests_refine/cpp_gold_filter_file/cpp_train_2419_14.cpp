#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int num, t, b;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> t >> b;
    if (t % b == 0) {
      cout << 0 << '\n';
    } else if (t < b) {
      cout << b - t << '\n';
    } else {
      cout << b * (t / b + 1) - t << '\n';
    }
  }
  return 0;
}
