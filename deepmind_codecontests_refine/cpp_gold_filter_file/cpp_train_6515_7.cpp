#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, mx = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mx = max(mx, x);
  }
  cout << (mx ^ x);
}
