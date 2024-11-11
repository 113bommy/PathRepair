#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, p;
  cin >> n >> m;
  p = n / 2 + (n % 2 != 0);
  for (int i = p; i < n; i++) {
    if (i % m == 0) {
      cout << i;
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
