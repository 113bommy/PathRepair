#include <bits/stdc++.h>
using namespace std;
int a, b, c, n, d, k, i;
int main() {
  cin >> n;
  if (n <= 3) {
    cout << -1;
  } else {
    for (i = n - 1; i > 0; i--) {
      cout << i << " ";
    }
  }
}
