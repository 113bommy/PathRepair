#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a >= 0 && n <= 100 && b < n) {
    cout << n - max(a + 1, n - b) + 1;
  }
  return 0;
}
