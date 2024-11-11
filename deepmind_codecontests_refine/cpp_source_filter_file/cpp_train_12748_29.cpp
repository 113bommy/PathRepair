#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x = 2;
  do {
    cin >> n;
  } while ((n < 2) || (n > 100));
  cout << x << " ";
  for (int i = 2; i < n; i++) {
    x = x + i;
    if (x >= n) {
      x = x - n;
    }
    cout << x << " ";
  }
}
