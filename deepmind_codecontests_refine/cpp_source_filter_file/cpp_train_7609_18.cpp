#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int mn = 999999, mx = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mn = min(mn, x);
    mx = max(mx, x);
  }
  cout << max(0, (mx - mn) - n + 1);
}
