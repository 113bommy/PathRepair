#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  if (a % 2 == 1) {
    cout << (a + 1) / 2;
  } else {
    cout << 1 + (n - a) / 2;
  }
  return 0;
}
