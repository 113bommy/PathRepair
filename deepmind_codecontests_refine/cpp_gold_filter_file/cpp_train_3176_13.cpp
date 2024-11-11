#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n == 1 && k == 10) {
    cout << -1;
    return 0;
  } else {
    if (k == 10) k = 1;
    cout << k;
    for (int i = 0; i < n - 1; i++) cout << 0;
  }
}
