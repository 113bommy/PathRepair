#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, b = 0;
  cin >> t;
  if (t == 2) {
    cout << 2;
    return 0;
  }
  for (int i = 1; i < t; i++) {
    b = (b + i) % t;
    cout << b + 1 << " ";
  }
  return 0;
}
