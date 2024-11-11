#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    x = x + i;
    x = (x - 1) % n + 1;
    cout << x << " ";
  }
  return 0;
}
