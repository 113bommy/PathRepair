#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x, y;
  cin >> x >> y;
  if (y == 0) {
    puts("No");
    return 0;
  }
  if (y == 1 && x == 2) {
    puts("No");
    return 0;
  }
  if (!(abs(x - y) % 2)) {
    puts("No");
    return 0;
  }
  if (x + 1 < y) {
    puts("No");
    return 0;
  }
  puts("Yes");
  return 0;
}
