#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  for (int i = 1; i < n; i++) {
    if (((n * i) % 10 == 0) || ((n * i) - c) % 10 == 0) {
      cout << i;
      break;
    }
  }
  return 0;
}
