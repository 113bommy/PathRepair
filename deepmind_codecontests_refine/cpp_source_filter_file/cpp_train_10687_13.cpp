#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    if (n % 10 == 0) {
      n /= 10;
    } else {
      n -= k;
    }
  }
  cout << n;
}
