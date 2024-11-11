#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 10000; i++) {
    if (i * (i - 1) >= n) {
      cout << i * 2 + (i - 1) * 2;
      return 0;
    }
    if (i * i >= n) {
      cout << i * 4;
      return 0;
    }
  }
  return 0;
}
