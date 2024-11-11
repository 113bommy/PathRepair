#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
  cin >> n >> t;
  if (n == 1 && t == 10) {
    cout << -1;
    return 0;
  }
  if (t == 10) {
    cout << 1;
    for (int i = 1; i < n; i++) {
      cout << 0;
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cout << t;
  }
  return 0;
}
