#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b < n) {
    cout << 1 + b;
  } else if (a + b == n) {
    cout << b;
  } else if (a + b > n) {
    cout << b - 1;
  }
}
