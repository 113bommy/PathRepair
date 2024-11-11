#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int x, n;
  cin >> x >> n;
  for (long long i = 0; i < 50000000; i++) {
    if ((x % n) == 0) {
      cout << "Yes\n";
      return 0;
    } else
      x += x % n;
  }
  cout << "No\n";
  return 0;
}
