#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);
  long long l, r, k;
  cin >> l >> r >> k;
  long long c = 1;
  bool foundOne = false;
  for (int i = 0; i < 200; ++i) {
    if (l <= c && c <= r) {
      foundOne = true;
      cout << c << ' ';
    }
    if (c * k / k != c) {
      break;
    }
    c *= k;
  }
  if (!foundOne) {
    cout << -1;
  }
  cout << endl;
  return 0;
}
