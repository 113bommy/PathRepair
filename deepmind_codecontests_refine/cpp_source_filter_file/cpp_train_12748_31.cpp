#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, b = 1;
  cin >> t;
  if (t == 2) {
    cout << 2;
    return 0;
  }
  for (int i = 1; i < t; i++) {
    b = (b + i) % t;
    cout << b << " ";
  }
  return 0;
}
