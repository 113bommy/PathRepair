#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int q = 1, a;
  for (int i = 1; i < n; i++) {
    q = q + i;
    if (q != n) {
      q = (q) % (n);
      cout << q << " ";
    }
    if (q == n) {
      cout << q << " ";
      q = 0;
    }
  }
  return 0;
}
