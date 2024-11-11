#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b > n) {
    cout << b + 1;
  } else if (a + b == n) {
    cout << b;
  } else {
    cout << 0;
  }
  return 0;
}
