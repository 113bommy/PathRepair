#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k <= (n + 1) / 2) {
    cout << 1 + 2 * (k - 1);
  } else {
    k = n - (n + 1) / 2;
    cout << 2 * k;
  }
  return 0;
}
