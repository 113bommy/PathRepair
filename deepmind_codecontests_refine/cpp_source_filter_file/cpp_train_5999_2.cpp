#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, mx, ans;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    mx = max(mx, a);
  }
  cout << max(0, mx - 25);
  return 0;
}
