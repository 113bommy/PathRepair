#include <bits/stdc++.h>
using namespace std;
int a, b, c, n, d, k, i;
int main() {
  cin >> n;
  if (n <= 2) {
    cout << -1;
  } else {
    for (i = n; i >= 1; i--) {
      cout << i << " ";
    }
  }
}
