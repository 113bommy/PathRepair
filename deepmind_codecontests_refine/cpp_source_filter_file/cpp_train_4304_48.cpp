#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    exit(0);
  }
  if (n == 2) {
    cout << 13;
    exit(0);
  }
  int d = 24;
  int ops = 12;
  int ans = 1;
  for (int i = 0; i < n - 2; i++) {
    ans += d;
    d += ops;
  }
  cout << ans;
}
